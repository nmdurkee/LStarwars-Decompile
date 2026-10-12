/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2710; label: FUN_006c2710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2710(undefined4 param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  puVar2 = &DAT_02973fe8;
  iVar3 = 1;
  do {
    if (((iVar3 - 1U < 10) && (puVar2 != (uint *)0x14c)) && ((puVar2[-0x2a] & 1) != 0)) {
      param_2 = *(int *)(param_2 + 4);
      puVar2[-0x2a] = puVar2[-0x2a] | 2;
      *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) | 1;
    }
    if (((-1 < iVar3) && (iVar3 < 10)) && ((puVar2 != (uint *)0xa4 && ((*puVar2 & 1) != 0)))) {
      param_2 = *(int *)(param_2 + 4);
      *puVar2 = *puVar2 | 2;
      *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) | 1;
    }
    if (((-1 < iVar3 + 1) && (iVar3 + 1 < 10)) &&
       ((puVar2 != (uint *)0xfffffffc && ((puVar2[0x2a] & 1) != 0)))) {
      param_2 = *(int *)(param_2 + 4);
      puVar2[0x2a] = puVar2[0x2a] | 2;
      *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) | 1;
    }
    if ((((-1 < iVar3 + 2) && (iVar3 + 2 < 10)) && (puVar2 != (uint *)0xffffff54)) &&
       ((puVar2[0x54] & 1) != 0)) {
      param_2 = *(int *)(param_2 + 4);
      puVar2[0x54] = puVar2[0x54] | 2;
      *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) | 1;
    }
    if (((-1 < iVar3 + 3) && (iVar3 + 3 < 10)) &&
       ((puVar2 != (uint *)0xfffffeac && ((puVar2[0x7e] & 1) != 0)))) {
      param_2 = *(int *)(param_2 + 4);
      puVar2[0x7e] = puVar2[0x7e] | 2;
      *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) | 1;
    }
    iVar1 = iVar3 + 4;
    puVar2 = puVar2 + 0xd2;
    iVar3 = iVar3 + 5;
  } while (iVar1 < 10);
  return;
}

