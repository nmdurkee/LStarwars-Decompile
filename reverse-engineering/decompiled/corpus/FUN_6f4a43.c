/* Ghidra analysis pseudocode, not original source.
 * ev_89d123adc6bf396b2f6b4ec3563e25957edd0c204114ec20eecbaddaafaf9a77
 * Entry: 0x6f4a43; label: ___unDNameHelper
 */

/* Library Function - Single Match
    ___unDNameHelper
   
   Library: Visual Studio 2005 Release */

void ___unDNameHelper(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((short)param_4 == 0) {
    param_4 = 0x2800;
  }
  ___unDName(param_1,param_2,param_3,_malloc,_free,param_4);
  return;
}

