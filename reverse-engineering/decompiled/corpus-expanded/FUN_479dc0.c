/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x479dc0; label: FUN_00479dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00479dc0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  float10 fVar5;
  
  if ((((*(char *)(param_1 + 0x14) == '\0') && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94))
      && (_DAT_00950780 == 0.0)) &&
     ((DAT_0093b2b4 != (ushort *)0x0 && (DAT_0093b2b8 <= (int)(uint)*DAT_0093b2b4)))) {
    iVar2 = 0;
    iVar4 = 0;
    piVar3 = &DAT_0093d7f0;
    do {
      iVar1 = *piVar3;
      if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) {
        iVar4 = iVar4 + 1;
        fVar5 = (float10)FUN_005b3cf0(iVar1 + 0x5c,&DAT_007fa204,0);
        if (fVar5 < (float10)4.0) {
          iVar2 = iVar2 + 1;
        }
      }
      piVar3 = piVar3 + 1;
    } while ((int)piVar3 < 0x93d7f8);
    if ((0 < iVar4) && (iVar2 == iVar4)) {
      *(undefined1 *)(param_1 + 3) = 4;
      return 1;
    }
  }
  return 0;
}

