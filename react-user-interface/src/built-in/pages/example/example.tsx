import React, {useEffect} from "react";
import './example.scss'
import "../../../cpp-window"
import {Helmet} from "react-helmet-async";

const Example: React.FC = () => {
    useEffect(() => {
        const element = document.getElementById("message");
        if (element != null) {
            element.innerText = window.exampleMessage();
        }
    }, []);
    return (
        <>
            <Helmet title="Example title"/>
            <div className="example">
                Congratulations on your successful installation. Happy hacking!
            </div>
            <div className="example" id="message">
            </div>
        </>
    );
}

export default Example