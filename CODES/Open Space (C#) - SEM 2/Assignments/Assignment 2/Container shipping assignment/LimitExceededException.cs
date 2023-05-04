using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    //limit has been exceeded exception
    public class LimitExceededException : Exception
    {
        /// <summary>
        /// this class is to throw exceptions specifically for cases where weight has been exceeded.
        /// </summary>
        public LimitExceededException() : base("Limit exceeded exception") { }
        public LimitExceededException(string message) : base(message) { }
        public LimitExceededException (string message, Exception innerException) 
            : base(message, innerException) { }
    }
}
