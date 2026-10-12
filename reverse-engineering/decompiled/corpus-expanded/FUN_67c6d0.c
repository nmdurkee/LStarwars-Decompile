/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c6d0; label: FUN_0067c6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067c6d0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  if (((DAT_0292fc68 != (int *)0x0) && (param_1 != -1)) &&
     (sVar3 = *(short *)((int)DAT_02924af4 + param_2 * 2 + 0xc), sVar3 != -1)) {
    iVar1 = *DAT_02924af4 + sVar3 * 0x38;
    iVar2 = *DAT_0292fc68 + *(short *)(DAT_0292fc68[0x1a] + 0x48 + param_1 * 0x6c) * 0x38;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar1 + 0x34);
  }
  return;
}

