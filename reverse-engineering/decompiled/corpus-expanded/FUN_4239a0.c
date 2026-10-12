/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4239a0; label: FUN_004239a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004239a0(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  *(undefined2 *)(unaff_ESI + 4) = 0;
  iVar1 = FUN_0054fa60();
  *(undefined2 *)(unaff_ESI + 3) = 0;
  *(undefined2 *)((int)unaff_ESI + 0xe) = 0;
  unaff_ESI[2] = (float)iVar1 * 1.5259022e-05 * 0.5 * 0.5;
  unaff_ESI[1] = 0;
  *unaff_ESI = 0;
  return;
}

