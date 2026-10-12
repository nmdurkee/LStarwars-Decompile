/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c9e40; label: FUN_006c9e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c9e40(int param_1,int param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x24);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if ((puVar1[3] == param_1) && ((param_2 == 0 || (puVar1[4] == param_2)))) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}

