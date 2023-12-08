import React from 'react'
import { render } from 'react-snapshot'
import App from './built-in/App'
import Example from "./built-in/pages/example/example"


const routes = [
    {
        path: '/',
        component: Example,
        exact: true
    }
]


const rootEl = document.getElementById('root')
render(<App routes={routes}/>, rootEl)

