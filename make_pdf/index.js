const md = require("markdown-it")();
const path = require("path");
const filePath = path.resolve(__dirname, "../README.md");
const fs = require("fs");
const imgs = [
  {
    path: "./src/main.cpp",
    src: "../assets/main.png",
  },
  {
    src: "../assets/functions.png",
    path: "./src/Functions.cpp",
  },
];
const renderHtml = () => {
  return `<div>
  <figure><figcaption>File: ./src/main.cpp</figcaption><img src="../assets/main.png" width="500"/></figure></div>
  
  <div><figure><figcaption>File: ./src/Functions.cpp</figcaption><img src="../assets/functions.png" width="500"/></figure>

  </div>
  <style>
  body {
    margin: 5px;
    padding: 5px;
    text-align: center;
  }</style>`;
};

const main = md.render(fs.readFileSync(filePath).toString());
const html = `${main}<br />${renderHtml()}`;
fs.writeFileSync("output.html", html, (err, html) => {
  console.log("FILE WRITTEN", err, html);
});
