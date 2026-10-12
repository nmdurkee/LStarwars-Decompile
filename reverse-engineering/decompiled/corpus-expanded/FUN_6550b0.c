/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x6550b0; label: FUN_006550b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006550b0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_02962094 <= DAT_029211e8) {
    return -1;
  }
  sVar1 = *(short *)(DAT_02962084 + DAT_029211e8 * 2);
  DAT_029211e8 = DAT_029211e8 + 1;
  iVar2 = sVar1 * 0x330;
  iVar3 = iVar2 + 0x100;
  iVar4 = 0x20;
  do {
    *(undefined4 *)(iVar3 + DAT_029620a4) = 0;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined2 *)(iVar2 + 0x180 + DAT_029620a4) = 0;
  *(undefined2 *)(iVar2 + 0x18a + DAT_029620a4) = 0;
  *(undefined2 *)(iVar2 + 0x186 + DAT_029620a4) = 0;
  *(undefined2 *)(iVar2 + 0x18c + DAT_029620a4) = 0;
  *(undefined2 *)(iVar2 + 0x18e + DAT_029620a4) = 0;
  *(undefined2 *)(iVar2 + 0x188 + DAT_029620a4) = 0;
  *(undefined2 *)(iVar2 + 0x2f2 + DAT_029620a4) = 0xffff;
  *(undefined4 *)(iVar2 + 0x2fc + DAT_029620a4) = 0;
  *(undefined1 *)(iVar2 + 0x2f4 + DAT_029620a4) = 1;
  *(undefined1 *)(iVar2 + 0x2f6 + DAT_029620a4) = 1;
  *(undefined1 *)(iVar2 + 0x2f7 + DAT_029620a4) = 1;
  *(undefined4 *)(iVar2 + 0x32c + DAT_029620a4) = 0;
  *(short *)(iVar2 + 0x32a + DAT_029620a4) = sVar1;
  *(undefined1 *)(iVar2 + 0x2fa + DAT_029620a4) = 0;
  return (int)sVar1;
}

