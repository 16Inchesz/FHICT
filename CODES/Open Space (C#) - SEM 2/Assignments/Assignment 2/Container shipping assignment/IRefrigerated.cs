using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    //interface to check if container needs to be refrigerated.
    public interface IRefrigerated
    {
        bool NeedsRefrigeration();  
    }
}
