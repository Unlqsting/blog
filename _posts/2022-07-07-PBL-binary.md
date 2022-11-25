---
title: Binary Math
layout: default
description: A Binary Math illustrative application using HTML, Liquid, and JavaScript.
permalink: /frontend/binary
image: /images/binary.png
categories: [3.B, 3.C, C4.4]
tags: [html, liquid, javascript]
week: 13
type: pbl
---

<!-- Hack 1: add a character display to text when 8 bits, determine if printable or not printable -->
<!-- Hack 2: change to 24 bits and add a color code and display color when 24 bits, think about display on this one -->
<!-- Hack 3: do your own thing -->

{% assign BITS = 3 %}

<div class="container bg-primary">
    <header class="pb-3 mb-4 border-bottom border-primary text-dark">
        <span class="fs-4">Binary Math with Conversions</span>
    </header>
    <div class="row justify-content-md-center">
        <div class="col-8">
            <table class="table">
            <tr id="table">
                <th>Plus</th>
                <th>Binary</th>
                <th>Octal</th>
                <th>Hexadecimal</th>
                <th>Decimal</th>
                <th>Minus</th>
            </tr>
            <tr>
                <td><button type="button" id="add1" onclick="add(1)">+1</button></td>
                <td id="binary">00000000</td>
                <td id="octal">0</td>
                <td id="hexadecimal">0</td>
                <td id="decimal">0</td>
                <td><button type="button" id="sub1" onclick="add(-1)">-1</button></td>
            </tr>
            </table>
        </div>
        <div class="col-12">
            <table class="table">
            <tr>
                <td><img class="img-responsive py-3" id="bulb0" src="/blog/images/bulb_off.png" alt="" width="40" height="Auto" />
                    <button type="button" id="butt0" onclick="javascript:toggleBit(0)">Turn on</button>
                <figcaption value="4" class="text labels" id="label1" >Decimal bit value: 4</figcaption>
                </td>
                <!--  -->
                <td><img class="img-responsive py-3" id="bulb1" src="/blog/images/bulb_off.png" alt="" width="40" height="Auto" />
                    <button type="button" id="butt1" onclick="javascript:toggleBit(1)">Turn on</button>
                <figcaption value="2" class="text labels" id="label1" >Decimal bit value: 2</figcaption>
                </td>
                <!--  -->
                <td><img class="img-responsive py-3" id="bulb2" src="/blog/images/bulb_off.png" alt="" width="40" height="Auto" />
                    <button type="button" id="butt2" onclick="javascript:toggleBit(2)">Turn on</button>
                <figcaption value="1" class="text labels" id="label1" >Decimal bit value: 1</figcaption>
                </td>
                <td>
                </td>
                <!--  -->
            </tr>
            <tr>
                <td><input type="text" id="digit0" value="Binary bit value: 0" size="15" readonly="" /></td>
                <td><input type="text" id="digit1" value="Binary bit value: 0" size="15" readonly="" /></td>
                <td><input type="text" id="digit2" value="Binary bit value: 0" size="15" readonly="" /></td> 
            </tr>
            </table>
        </div>
    </div>
    <div id="bitnumber">
    </div>
    <div class="convertcontainer">
        <h2>Decimal to Binary converter</h2>
        <div class="inputcontainer">
            <div class="inputs">
                <label for="decimalinp">Decimal:</label>
                <input type="number" id="decimalinp" />
                <label for="bininp">Binary:</label>
                <input type="number" id="bininp" /> 
            </div>
        </div>
    </div>
</div>
</div>

<style>
    #bitnumber {
        width: 450px;
        height: 200px;
        color: bisque;
        background-color: black;
        display: flex;
        font-size: 60px;
        justify-content: center;
        padding: 5px;
    }
    .convertcontainer {
        background-color: black;
        width: 300px;
        padding: 5px 4px;
        border-radius: 3px;
        box-shadow: 0px 2px 2px rgba(0,21,33,0.18);
        display: flex;
        position: absolute;
        transform: translateX(550px);
        float: right;
        top: 50%;
        bottom: 25%;
        height: 200px;
    }
    h2 {
        font-size: 20px;
        color: bisque;
        text-align: center;
        font-weight: 500;
    }
    .inputcontainer {
        display: flex;
        justify-content: center;
        gap: 4px;
        position: absolute;
        transform: translateY(75px);
    }
    input {
        position: relative;
        font-size: 15px;
        width: 100%;
        padding: 2px;
        border-radius: 3px;
        outline: none;
    }
</style>

<script>
    
    //script for binary converter:
        let decimalinp = document.getElementById("decimalinp");

        let bininp = document.getElementById("bininp");

        //converting decimal to binary with user input
            decimalinp.addEventListener("input", () => {
                let decimalval = parseInt(decimalinp.value);
                //decimalval converts decimal to binary

                bininp.value = decimalval.toString(2);
            });
    //
    
    const BITS = {{ BITS }};
    const MAX = 2 ** BITS - 1;
    const MSG_ON = "Turn on";
    const IMAGE_ON = "{{site.baseurl}}/images/bulb_on.gif";
    const MSG_OFF = "Turn off";
    const IMAGE_OFF = "{{site.baseurl}}/images/bulb_off.png"

    // return string with current value of each bit
    function getBits() {
        let bits = "";
        for(let i = 0; i < BITS; i++) {
        bits = bits + document.getElementById('digit' + i).value;
        }
        return bits;
    }
    // setter for DOM values
    function setConversions(binary) {
        document.getElementById('binary').innerHTML = binary;
        // Octal conversion
        document.getElementById('octal').innerHTML = parseInt(binary, 2).toString(8);
        // Hexadecimal conversion
        document.getElementById('hexadecimal').innerHTML = parseInt(binary, 2).toString(16);
        // Decimal conversion
        document.getElementById('decimal').innerHTML = parseInt(binary, 2).toString();
        //
        document.getElementById('bitnumber').innerText = "Decimal number: " + parseInt(binary, 2).toString();
    }
    //
    function decimal_2_base(decimal, base) {
        let conversion = "";
        // loop to convert to base
        do {
        let digit = decimal % base;
        conversion = "" + digit + conversion; // what does this do?
        decimal = ~~(decimal / base);         // what does this do?
        } while (decimal > 0);                  // why while at the end? what is ~~?
        // loop to pad with zeros
        if (base === 2) {                        // only pad for binary conversions
        for (let i = 0; conversion.length < BITS; i++) {
            conversion = "0" + conversion;
        }
        }
        return conversion;
    }

    // toggle selected bit and recalculate
    function toggleBit(i) {
        //alert("Digit action: " + i );
        const dig = document.getElementById('digit' + i);
        const image = document.getElementById('bulb' + i);
        const butt = document.getElementById('butt' + i);
        // Change digit and visual
        if (image.src.match(IMAGE_ON)) {
        dig.value = 0;
        image.src = IMAGE_OFF;
        butt.innerHTML = MSG_ON;
        } else {
        dig.value = 1;
        image.src = IMAGE_ON;
        butt.innerHTML = MSG_OFF;
        }
        // Binary numbers
        const binary = getBits();
        setConversions(binary);
    }
    // add is positive integer, subtract is negative integer
    function add(n) {
        let binary = getBits();
        // convert to decimal and do math
        let decimal = parseInt(binary, 2);
        if (n > 0) {  // PLUS
        decimal = MAX === decimal ? 0 : decimal += n; // OVERFLOW or PLUS
        } else  {     // MINUS
        decimal = 0 === decimal ? MAX : decimal += n; // OVERFLOW or MINUS
        }
        // convert the result back to binary
        binary = decimal_2_base(decimal, 2);
        // update conversions
        setConversions(binary);
        // update bits
        for (let i = 0; i < binary.length; i++) {
        let digit = binary.substr(i, 1);
        document.getElementById('digit' + i).value = digit;
        if (digit === "1") {
            document.getElementById('bulb' + i).src = IMAGE_ON;
            document.getElementById('butt' + i).innerHTML = MSG_OFF;
        } else {
            document.getElementById('bulb' + i).src = IMAGE_OFF;
            document.getElementById('butt' + i).innerHTML = MSG_ON;
        }
        }
    }
</script>
