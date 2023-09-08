using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Live_Test
{
    /// <summary>
    /// This interface acts as the product interface used to get details of a product, prepare them, and check the water levels.
    /// </summary>
    public interface IProduct
    {
        string Name { get; set; }
        float Price { get;set; }
        float AmountOfWater { get; set; }

        void Prepare();
        bool CheckWaterLevel();
    }
}
