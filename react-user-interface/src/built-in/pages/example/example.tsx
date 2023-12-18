import React, {useEffect} from "react";
import {Helmet} from "react-helmet-async";
import {Link} from "react-router-dom";
import './example.scss'
import "../../../cpp-window" // It necessary for JS bindings

// The example page with simple JS bindings. You don`t need to use it in project. You can delete it
const Example: React.FC = () => {
    useEffect(() => {
        const element = document.getElementById("message");
        if (element != null) {
            element.innerText = window.exampleMessage(); // getting message from cpp or from .js
        }
    }, []);
    return (
        <>
            <Helmet title="Example title"/>
            <div className="example">
                Congratulations on your successful installation. Happy hacking!
                <Link to="https://google.com">TO GOOGLE!!!</Link> {/*Use Link component instead of <a> tag*/}
            </div>
            <div className="example" id="message">
            </div>
        </>
    );
}

export default Example