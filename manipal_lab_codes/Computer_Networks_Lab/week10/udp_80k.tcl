
#Create a simulator object
set ns [new Simulator]

#Define different colors for data flows (for NAM)
$ns color 1 Green
#$ns color 2 Red

#Open the NAM trace file
set nf [open 80.nam w]
$ns namtrace-all $nf

#open the trace file
set f [open 80.tr w]
$ns trace-all $f


#Define a 'finish' procedure
proc finish {} {
        global ns nf f
        $ns flush-trace
        #Close the NAM trace file
        close $nf
	close $f
        #Execute NAM on the trace file
        exec nam 80.nam &
        exit 0
}

#Create four nodes
set s [$ns node]
set r [$ns node]
set d [$ns node]


#Create links between the nodes
$ns duplex-link $s $r 1Mb 50ms DropTail
$ns duplex-link $r $d 100kbps 5ms DropTail


#Set Queue Size of link (n2-n3) to 10
$ns queue-limit $s $r 10
$ns queue-limit $r $d 10

#Give node position (for NAM)
$ns duplex-link-op $s $r orient right
$ns duplex-link-op $r $d orient right


#Monitor the queue for link (n2-n3). (for NAM)
$ns duplex-link-op $s $r queuePos 0.5
$ns duplex-link-op $r $d queuePos 0.5






#Setup a UDP connection
set udp [new Agent/UDP]
$ns attach-agent $s $udp
set null [new Agent/Null]
$ns attach-agent $d $null
$ns connect $udp $null
$udp set fid_ 2

#Setup a CBR over UDP connection (1000 bytes every 10ms)
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set random_ false
$cbr set rate_ 80kb


#Schedule events for the CBR and FTP agents
$ns at 0.1 "$cbr start"
$ns at 10.1 "$cbr stop"

#Detach tcp and sink agents (not really necessary)
#$ns at 4.5 "$ns detach-agent $n0 $tcp ; $ns detach-agent $n3 $sink"

#Call the finish procedure after 5 seconds of simulation time
$ns at 11 "finish"

#Print CBR packet size and interval
puts "CBR packet size = [$cbr set packet_size_]"
puts "CBR interval = [$cbr set interval_]"

#Run the simulation
$ns run

