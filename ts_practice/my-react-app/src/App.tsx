import React from 'react';
import './App.css';
import { Route, BrowserRouter as Router , Routes} from 'react-router-dom';
import Home from './pages/Home';
import Report from './pages/Report';
import NoMatch from './pages/NoMatch';
import AppLayout from './components/layout/AppLayout';

function App() {
  return (
    <Router>
      <Routes>
       <Route path="/" element={<AppLayout />}>
        <Route index element={<Home/>}/> 
        <Route path="/report" element={<Report/>}/>
        <Route path="*" element={<NoMatch/>}/>
      </Route> 
      </Routes>
    </Router>
  );
}

export default App;


/*
一:ルーティングとは？
ルーティング（Routing）とは、ユーザーが特定のURLにアクセスしたときに、
どのコンポーネントやページを表示するかを決定する仕組みのことです。

特にシングルページアプリケーション（SPA）においては、
ページ全体を再読み込みせずにURLの変更に応じて異なるコンテンツを表示するために重要です。


*/