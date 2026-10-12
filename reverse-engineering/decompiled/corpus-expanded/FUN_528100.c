/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x528100; label: FUN_00528100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00528100(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = DAT_009238e4;
  *(undefined4 *)(DAT_009238e4 + 0x43814) = 0;
  *(undefined4 *)(iVar2 + 0x43818) = 0;
  iVar2 = 0;
  do {
    FUN_004f1310(DAT_009238e4 + 0x4380c,iVar2 + 0x4120c + DAT_009238e4);
    iVar2 = iVar2 + 0x4c;
  } while (iVar2 < 0x2600);
  iVar2 = *(int *)(DAT_009238e4 + 100);
  iVar1 = 0;
  if (0 < *(int *)(iVar2 + 0x137c)) {
    iVar3 = 0;
    do {
      puVar4 = (undefined4 *)(*(int *)(iVar2 + 0x1380) + iVar3);
      iVar2 = FUN_005274f0();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 8) = *puVar4;
        *(undefined4 *)(iVar2 + 0xc) = puVar4[1];
        *(undefined4 *)(iVar2 + 0x10) = puVar4[2];
        *(undefined4 *)(iVar2 + 0x14) = puVar4[3];
        *(float *)(iVar2 + 0x18) = (float)puVar4[4] - (float)puVar4[1];
        *(float *)(iVar2 + 0x1c) = (float)puVar4[6] - (float)puVar4[1];
        *(undefined1 *)(iVar2 + 0x48) = *(undefined1 *)((int)puVar4 + 0x49);
        *(undefined4 *)(iVar2 + 0x20) = puVar4[8];
        *(undefined4 *)(iVar2 + 0x24) = puVar4[9];
        *(undefined4 *)(iVar2 + 0x28) = puVar4[10];
        *(undefined4 *)(iVar2 + 0x2c) = puVar4[0xb];
        *(undefined4 *)(iVar2 + 0x30) = puVar4[0xc];
        *(undefined4 *)(iVar2 + 0x34) = puVar4[0xd];
        *(undefined4 *)(iVar2 + 0x38) = puVar4[0xf];
        *(undefined4 *)(iVar2 + 0x3c) = puVar4[0xe];
        *(undefined4 *)(iVar2 + 0x40) = puVar4[0x10];
        *(undefined4 *)(iVar2 + 0x44) = puVar4[0x11];
        *(undefined1 *)(iVar2 + 0x49) = *(undefined1 *)((int)puVar4 + 0x4a);
      }
      iVar2 = *(int *)(DAT_009238e4 + 100);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x58;
    } while (iVar1 < *(int *)(iVar2 + 0x137c));
  }
  return;
}

