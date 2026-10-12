/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639270; label: FUN_00639270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639270(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (DAT_02913778 != '\0') {
    FUN_006378f0();
    if (DAT_02913824 == (undefined4 *)0x0) {
      FUN_00639150();
      return;
    }
    uVar1 = DAT_02913824[2];
    uVar2 = DAT_02913824[1];
    uVar3 = *DAT_02913824;
    puVar5 = &DAT_02913720;
    puVar6 = DAT_02913824;
    for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    if (DAT_02913818 == 0) {
      *(undefined1 *)((int)DAT_02913824 + 0x7a) = 0xff;
      *(undefined1 *)((int)DAT_02913824 + 0x79) = 0xff;
    }
    else {
      *(undefined1 *)((int)DAT_02913824 + 0x79) = *(undefined1 *)(DAT_02913818 + 0x79);
      if (*(char *)((int)DAT_02913824 + 0x79) != -1) {
        iVar4 = (int)DAT_02913824 + (-4 - DAT_0291389c);
        *(char *)(*(char *)((int)DAT_02913824 + 0x79) * 0x8c + 0x7e + DAT_0291389c) =
             (char)(iVar4 / 0x8c) - (char)(iVar4 / -0x74000000);
      }
      iVar4 = (DAT_02913818 - DAT_0291389c) + -4;
      *(char *)((int)DAT_02913824 + 0x7a) = (char)(iVar4 / 0x8c) - (char)(iVar4 / -0x74000000);
      iVar4 = (int)DAT_02913824 + (-4 - DAT_0291389c);
      *(char *)(DAT_02913818 + 0x79) = (char)(iVar4 / 0x8c) - (char)(iVar4 / -0x74000000);
    }
    *DAT_02913824 = uVar3;
    DAT_02913824[1] = uVar2;
    DAT_02913824[2] = uVar1;
  }
  return;
}

