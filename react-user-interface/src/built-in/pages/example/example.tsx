import React, {useEffect} from "react";
import './example.scss'
import "../../../cpp-window"
import {Helmet} from "react-helmet-async";
import {Link} from "react-router-dom";

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
                Congratulations on your successful installation. Happy hacking! <Link to="https://google.com">TO
                GOOGLE!!!</Link>
            </div>
            <div className="example" id="message">
            </div>
        </>
    );
}

export default Example