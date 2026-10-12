/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x52a760; label: FUN_0052a760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052a760(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_54 [12];
  undefined4 uStack_48;
  float fStack_44;
  undefined4 uStack_40;
  undefined4 local_30;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 local_c;
  
  if (DAT_009238a0 != (code *)0x0) {
    for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x371a4); iVar1 != 0;
        iVar1 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar1)) {
      iVar4 = 0;
      if (*(char *)(iVar1 + 0x5b) != '\0') {
        do {
          local_30 = 0xffffffff;
          local_c = 0xffffffff;
          uVar2 = __allshl();
          if (((uVar2 & *(uint *)(iVar1 + 0x54)) != 0) && (iVar3 = FUN_00528af0(iVar1), iVar3 != 0))
          {
            FUN_0052a630(iVar1,iVar4,local_54,0);
            (*DAT_009238a0)(local_54,*(undefined2 *)(iVar1 + 0x34),(int)*(short *)(iVar1 + 0x58),0,
                            iVar1);
            iVar3 = *(int *)(iVar1 + 0x84);
            if (iVar3 != 0) {
              uStack_48 = *(undefined4 *)(iVar1 + 0x28);
              fStack_44 = *(float *)(iVar1 + 0x2c);
              uStack_40 = *(undefined4 *)(iVar1 + 0x30);
              uStack_24 = *(undefined4 *)(iVar3 + 0x18);
              fStack_20 = *(float *)(iVar3 + 0x1c);
              uStack_1c = *(undefined4 *)(iVar3 + 0x20);
              FUN_00512b00(&uStack_48,0,0);
            }
            iVar3 = *(int *)(iVar1 + 0x88);
            if (iVar3 != 0) {
              uStack_24 = *(undefined4 *)(iVar3 + 0x18);
              fStack_44 = *(float *)(iVar1 + 0x2c) + 0.1;
              local_30 = 0x8000;
              local_c = 0x8000;
              uStack_48 = *(undefined4 *)(iVar1 + 0x28);
              uStack_40 = *(undefined4 *)(iVar1 + 0x30);
              fStack_20 = *(float *)(iVar3 + 0x1c) + 0.1;
              uStack_1c = *(undefined4 *)(iVar3 + 0x20);
              FUN_00512b00(&uStack_48,0,0);
            }
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(uint)*(byte *)(iVar1 + 0x5b));
      }
    }
  }
  return;
}

