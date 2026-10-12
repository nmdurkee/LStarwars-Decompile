/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c3150; label: FUN_006c3150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c3150(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = (undefined4 *)*in_ECX;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if ((puVar1[3] == param_1) && ((param_2 == 0 || (puVar1[4] == param_2)))) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}

