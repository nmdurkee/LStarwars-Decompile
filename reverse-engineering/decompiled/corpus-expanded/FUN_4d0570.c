/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d0570; label: FUN_004d0570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d0570(void)

{
  int iVar1;
  float10 fVar2;
  
  if ((((((DAT_0087afcc != 0) && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b284)) &&
        ((&DAT_0086e0f5)[(uint)*(byte *)(DAT_0087afcc + 0x7c) * 0xc] == '\0')) &&
       (iVar1 = FUN_0058a900(0), iVar1 == 0)) &&
      (((DAT_0087a908 == 0 || (*(int *)(*(int *)(DAT_0087a908 + 0x34) + 0xc) != 0)) &&
       ((DAT_0087aa48 != 0 && ((*(byte *)(DAT_0087aa48 + 0x94) & 1) == 0)))))) &&
     (((DAT_0093d810 != 0 &&
       (fVar2 = (float10)FUN_005b3c50(DAT_0093d810 + 0x80,DAT_0087aa48 + 0x4c,0),
       fVar2 < (float10)25.0)) ||
      ((DAT_0093d814 != 0 &&
       (fVar2 = (float10)FUN_005b3c50(DAT_0093d814 + 0x80,DAT_0087aa48 + 0x4c,0),
       fVar2 < (float10)25.0)))))) {
    return 1;
  }
  return 0;
}

