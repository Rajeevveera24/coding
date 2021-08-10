<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Q2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:SqlDataSource ID="DS1" runat="server" ConnectionString="<%$ConnectionStrings:database %>"
                SelectCommand="SELECT * FROM Tours WHERE Place=@Place">
                <SelectParameters>
                    <asp:QueryStringParameter Name="Place" QueryStringField="Place" />
                </SelectParameters>
            </asp:SqlDataSource>
            <asp:GridView ID="GV1" DataSourceID="DS1" DataKeyNames="Place" runat="server" />
        </div>
    </form>
</body>
</html>
