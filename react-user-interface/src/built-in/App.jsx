import React, {useEffect} from 'react'
import {BrowserRouter as Router, Route, Switch} from 'react-router-dom'
import NotFound from "./pages/not-found/NotFound";
import './clear_styles.scss'



function App({routes}) {
    useEffect(() => {
        window.checkBrowserView();
    }, []);
    return (
        <Router>
            <div>
                <Switch>
                    {routes.map((route, i) => (
                        <Route key={i} {...route} />
                    ))}
                    <Route exact component={NotFound}/>
                </Switch>
            </div>
        </Router>
    )
}

export default App