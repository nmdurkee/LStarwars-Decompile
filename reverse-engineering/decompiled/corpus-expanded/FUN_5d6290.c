/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d6290; label: FUN_005d6290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005d6290(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = DAT_00973948;
  if (DAT_00973948 < 0x10) {
    iVar2 = DAT_00973948 * 0x420;
    DAT_00973948 = DAT_00973948 + 1;
    *(undefined4 *)(&DAT_0095fe7c + iVar2) = DAT_00966378;
    puVar4 = &DAT_009736e8;
    puVar5 = (undefined4 *)(&DAT_0095fbc0 + iVar2);
    for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(undefined4 *)(&DAT_0095fe80 + iVar2) = DAT_0097313c;
    *(undefined4 *)(&DAT_0095fe84 + iVar2) = _DAT_00966270;
    *(undefined4 *)(&DAT_0095fe88 + iVar2) = _DAT_0096dce4;
    puVar4 = &DAT_0080b708;
    puVar5 = (undefined4 *)(&DAT_0095fc38 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_0080b748;
    puVar5 = (undefined4 *)(&DAT_0095fc78 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_0080b7c8;
    puVar5 = (undefined4 *)(&DAT_0095fcb8 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_0080b808;
    puVar5 = (undefined4 *)(&DAT_0095fcf8 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_0080b848;
    puVar5 = (undefined4 *)(&DAT_0095fd38 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_0080b888;
    puVar5 = (undefined4 *)(&DAT_0095fd78 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_0080b8c8;
    puVar5 = (undefined4 *)(&DAT_0095fdb8 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_0080b908;
    puVar5 = (undefined4 *)(&DAT_0095fdf8 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = &DAT_0080b948;
    puVar5 = (undefined4 *)(&DAT_0095fe38 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(undefined4 *)(&DAT_0095fe78 + iVar2) = DAT_00973944;
    puVar4 = &DAT_00963fa0;
    puVar5 = (undefined4 *)(&DAT_0095fe90 + iVar2);
    for (iVar3 = 0x54; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    return iVar1 + 1;
  }
  return 0;
}

