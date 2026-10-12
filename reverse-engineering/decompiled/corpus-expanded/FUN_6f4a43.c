/* Ghidra pseudocode, not original source.
 * ev_8db3786b1d2e9370d3feb832809c6ae27354528dfff9c38ddb75cfb6eefed4ac
 * Entry: 0x6f4a43; label: ___unDNameHelper
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

