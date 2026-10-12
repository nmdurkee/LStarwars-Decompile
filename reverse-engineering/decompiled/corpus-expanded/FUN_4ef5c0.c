/* Ghidra pseudocode, not original source.
 * ev_04f8732b5525673103c3df9611ed7df2bf78b34f78235395bd9408faa7c2eefb
 * Entry: 0x4ef5c0; label: FUN_004ef5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef5c0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = CONCAT44(param_1,DAT_0088ab18);
  iVar3 = DAT_0088ab18;
  while (iVar3 != 0) {
    iVar1 = (int)uVar4;
    iVar3 = *(int *)(iVar1 + 0x10);
    if ((int)((ulonglong)uVar4 >> 0x20) <= iVar3) {
      uVar4 = FUN_004eedc0(iVar3 + 0x2c + iVar1,*(undefined4 *)(iVar1 + 8),
                           *(undefined4 *)(iVar1 + 0xc),iVar3);
    }
    piVar2 = (int *)uVar4;
    uVar4 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),*piVar2);
    if (*piVar2 == -0x1010102) {
      uVar4 = FUN_004eeda0();
    }
    if ((int *)uVar4 == (int *)0x0) break;
    if (*(int *)uVar4 == -0x1010102) {
      uVar4 = FUN_004eeda0();
    }
    iVar3 = (int)uVar4;
  }
  FUN_004eedc0();
  return;
}

