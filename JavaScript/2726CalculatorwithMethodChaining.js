// 2726. Calculator with Method Chaining

class Calculator {
  /**
   * @param {number} value
   */
  constructor(value) {
    this.result = value;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  add(value) {
    this.result += value;
    return this;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  subtract(value) {
    this.result -= value;
    return this;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  multiply(value) {
    this.result *= value;
    return this;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  divide(value) {
    if (value === 0) {
      throw new Error("Division by zero is not allowed");
    }
    this.result /= value;
    return this;
  }

  /**
   * @param {number} value
   * @return {Calculator}
   */
  power(value) {
    this.result = Math.pow(this.result, value);
    return this;
  }

  /**
   * @return {number}
   */
  getResult() {
    return this.result;
  }
}


const calc1 = new Calculator(10).add(5).subtract(7).getResult();   // 8
console.log(calc1);

const calc2 = new Calculator(2).multiply(5).power(2).getResult();  // 100
console.log(calc2);

try {
    const calc3 = new Calculator(20).divide(0).getResult();        // Throws error
} catch (err) {
    console.log(err.message);  // "Division by zero is not allowed"
}
