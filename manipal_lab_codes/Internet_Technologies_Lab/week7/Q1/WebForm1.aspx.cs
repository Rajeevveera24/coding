using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Q1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                List<string> Fruit = new List<string>();
                Fruit.Add("Mango");
                Fruit.Add("Orange");
                CheckBoxList1.DataSource = Fruit;
                List<string> IceCream = new List<string>();
                IceCream.Add("Black Current");
                IceCream.Add("Chocolate");
                IceCream.Add("Vanilla");
                RadioButtonList1.DataSource = IceCream;
                this.DataBind();
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int[] arr = { 10, 20, 30 };
            Random r = new Random();
            int num = r.Next(0, 3);
            Label1.Text = "The Milkshake you picked has <br/>Fruit: " + CheckBoxList1.SelectedItem.Text + "<br/>Ice-Cream: " + RadioButtonList1.SelectedItem.Text + "<br/><br/>The price of your milkshake is : Rs." + arr[num].ToString();
        }
    }
}