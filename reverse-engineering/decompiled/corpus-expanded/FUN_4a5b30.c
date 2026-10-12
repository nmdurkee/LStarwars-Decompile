/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a5b30; label: FUN_004a5b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a5b30(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  if (DAT_0087a96c != (int *)0x0) {
    iVar1 = *DAT_0087a96c;
    if ((((*(uint *)(iVar1 + 0x94) & 0x800000) == 0) && ((*(uint *)(iVar1 + 0x94) & 1) == 0)) &&
       (fVar2 = (float10)FUN_005b3c50(iVar1 + 0x30,param_1 + 0x30,0), fVar2 < (float10)0.010000001))
    {
      FUN_0055a250(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_0087a96c,1,0);
      FUN_00567800(iVar1,1,0xffffffff,0xffffffff,0,1);
    }
  }
  return;
}

