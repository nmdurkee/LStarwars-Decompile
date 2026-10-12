/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x5004e0; label: FUN_005004e0
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

