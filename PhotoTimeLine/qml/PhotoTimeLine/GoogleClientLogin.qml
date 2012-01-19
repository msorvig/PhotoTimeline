import Qt 4.7
import QtDesktop 0.1

Rectangle {
    id : googleClientLogin
    width: 640
    height: 480
    property bool rememberLogin : rememberPassword.checked
    property string username : userTextInput.text
    property string passwords : passwordTextInput.text
    signal login

    function login_internal()
    {
        statusText.text =  "Logging in";
        clientLogin.setLogin(userTextInput.text)
        clientLogin.setPassword(passwordTextInput.text)
        clientLogin.sendAuthenticationRequest()
        login()
    }

    function response()
    {
        statusText.text = "Response" + clientLogin.authenticationStateText
    }

    Connections {
        target: clientLogin
        onAuthenticationResponse : { response(); }
    }

    Grid {
        columns : 2
        spacing : 5

        Text {
            id : userText
            text : "User"
        }

        TextField {
            id : userTextInput
            text : username
            width : 200
        }

        Text {
            id : passwordText
            text : "Password"
        }

        TextField {
            id : passwordTextInput
            //echoMode : "Password"
            width : 200
        }

        CheckBox {
            id : rememberPassword
            checked : true
            text : "Remember Me"
        }

        Button {
            id: loginButton
            text: "Login"
            onClicked: { googleClientLogin.login_internal() }
        }

        Text {
            id: statusText
            text : "Status: Ready"
        }
    }
}
