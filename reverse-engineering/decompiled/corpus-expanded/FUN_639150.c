/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639150; label: FUN_00639150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639150(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_02913778 != '\0') {
    FUN_006378f0();
    DAT_02913824 = (undefined4 *)FUN_00637e10();
    if (DAT_02913824 != (undefined4 *)0x0) {
      puVar2 = &DAT_02913720;
      puVar3 = DAT_02913824;
      for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      if (DAT_02913818 == 0) {
        *(undefined1 *)((int)DAT_02913824 + 0x7a) = 0xff;
        *(undefined1 *)((int)DAT_02913824 + 0x79) = 0xff;
      }
      else {
        *(undefined1 *)((int)DAT_02913824 + 0x79) = *(undefined1 *)(DAT_02913818 + 0x79);
        if (*(char *)((int)DAT_02913824 + 0x79) != -1) {
          iVar1 = (int)DAT_02913824 + (-4 - DAT_0291389c);
          *(char *)(*(char *)((int)DAT_02913824 + 0x79) * 0x8c + 0x7e + DAT_0291389c) =
               (char)(iVar1 / 0x8c) - (char)(iVar1 / -0x74000000);
        }
        iVar1 = (DAT_02913818 - DAT_0291389c) + -4;
        *(char *)((int)DAT_02913824 + 0x7a) = (char)(iVar1 / 0x8c) - (char)(iVar1 / -0x74000000);
        iVar1 = (int)DAT_02913824 + (-4 - DAT_0291389c);
        *(char *)(DAT_02913818 + 0x79) = (char)(iVar1 / 0x8c) - (char)(iVar1 / -0x74000000);
      }
      *DAT_02913824 = DAT_029134a4;
      DAT_02913824[1] = DAT_029134a8;
      DAT_02913824[2] = DAT_029134ac;
    }
  }
  return;
}

