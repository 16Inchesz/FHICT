using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Live_Test
{
    /// <summary>
    /// this interface is used to check the temperature of the product.
    /// </summary>
    public interface ITemperatureControlledProduct
    {
        int Temperature { get; }
        bool IsHeated { get; }
    }
}
