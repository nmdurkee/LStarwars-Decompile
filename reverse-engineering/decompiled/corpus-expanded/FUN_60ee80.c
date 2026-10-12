/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60ee80; label: FUN_0060ee80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ee80(void)

{
  int iVar1;
  undefined *puVar2;
  int in_ECX;
  
  puVar2 = &DAT_028683e0;
  do {
    if (*(int *)(puVar2 + 0x4b0) == 0) {
      *(undefined4 *)(puVar2 + 0x4b0) = 1;
      goto LAB_0060eea7;
    }
    puVar2 = puVar2 + 0x4b4;
  } while (puVar2 != &DAT_028febe0);
  puVar2 = (undefined *)0x0;
LAB_0060eea7:
  if ((*(int *)(in_ECX + 4) == 0) || (puVar2 == (undefined *)0x0)) {
    FUN_0060f2d0();
  }
  else {
    iVar1 = *(int *)(in_ECX + 8);
    FUN_004ef660(puVar2 + iVar1,iVar1 + *(int *)(in_ECX + 4),*(int *)(in_ECX + 0xc) - iVar1);
  }
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (1 < *(uint *)(iVar1 + 0x4b0)) {
      *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
      *(undefined **)(in_ECX + 4) = puVar2;
      return;
    }
    *(undefined4 *)(iVar1 + 0x4b0) = 0;
  }
  *(undefined **)(in_ECX + 4) = puVar2;
  return;
}

