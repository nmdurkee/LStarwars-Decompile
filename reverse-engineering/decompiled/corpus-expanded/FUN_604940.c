/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x604940; label: FUN_00604940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00604940(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_1 + -1 < DAT_00973948) {
    iVar3 = (param_1 + -1) * 0x420;
    DAT_00966378 = *(undefined4 *)(&DAT_0095fe7c + iVar3);
    puVar5 = (undefined4 *)(&DAT_0095fbc0 + iVar3);
    puVar6 = &DAT_009736e8;
    for (iVar4 = 0x1e; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    DAT_0097313c = *(undefined4 *)(&DAT_0095fe80 + iVar3);
    _DAT_00966270 = *(undefined4 *)(&DAT_0095fe84 + iVar3);
    _DAT_0096dce4 = *(undefined4 *)(&DAT_0095fe88 + iVar3);
    fVar1 = -DAT_00973710;
    puVar5 = (undefined4 *)(&DAT_0095fc38 + iVar3);
    puVar6 = &DAT_0080b708;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = (undefined4 *)(&DAT_0095fc78 + iVar3);
    puVar6 = &DAT_0080b748;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = (undefined4 *)(&DAT_0095fcb8 + iVar3);
    puVar6 = &DAT_0080b7c8;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = (undefined4 *)(&DAT_0095fcf8 + iVar3);
    puVar6 = &DAT_0080b808;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = (undefined4 *)(&DAT_0095fd38 + iVar3);
    puVar6 = &DAT_0080b848;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = (undefined4 *)(&DAT_0095fd78 + iVar3);
    puVar6 = &DAT_0080b888;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = (undefined4 *)(&DAT_0095fdb8 + iVar3);
    puVar6 = &DAT_0080b8c8;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = (undefined4 *)(&DAT_0095fdf8 + iVar3);
    puVar6 = &DAT_0080b908;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    fVar2 = -DAT_00973708;
    puVar5 = (undefined4 *)(&DAT_0095fe38 + iVar3);
    puVar6 = &DAT_0080b948;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    DAT_00973944 = *(undefined4 *)(&DAT_0095fe78 + iVar3);
    FUN_005be2d0(fVar2,fVar1);
  }
  return;
}

