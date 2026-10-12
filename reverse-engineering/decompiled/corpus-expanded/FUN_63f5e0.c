/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x63f5e0; label: FUN_0063f5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0063f5e0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_0291389c != 0) {
    iVar2 = 0;
    piVar3 = (int *)(DAT_0291389c + 0x4618);
    do {
      if (*piVar3 == 0) {
        puVar1 = (undefined4 *)(iVar2 * 0x4c + 0x4604 + DAT_0291389c);
        if (puVar1 != (undefined4 *)0x0) {
          puVar1[5] = 1;
          puVar1[8] = DAT_0095e5c8;
          puVar1[9] = DAT_0095e5cc;
          puVar1[10] = DAT_0095e5d0;
          puVar1[7] = _DAT_0080fef0;
          puVar1[2] = 0x80808080;
          puVar1[3] = 0;
          *puVar1 = 0x41200000;
          puVar1[4] = 0;
          *(undefined1 *)(puVar1 + 6) = 1;
          puVar1[1] = 0x42c80000;
          puVar1[0xd] = 0x42c80000;
          puVar1[0xc] = 0x41200000;
          puVar1[0xb] = 0;
          puVar1[0xf] = 0;
          *(undefined2 *)(puVar1 + 0xe) = DAT_02973aa0;
        }
        return puVar1;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x13;
    } while (iVar2 < 0x20);
  }
  return (undefined4 *)0x0;
}

