/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x5004e0; label: FUN_005004e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_005004e0(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0092133c;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      FUN_004fff10(param_1);
      return (undefined4 *)0x0;
    }
    iVar2 = FUN_004f8b10(param_1,puVar1 + 2);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}

