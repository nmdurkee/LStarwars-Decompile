/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bc990; label: FUN_004bc990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bc990(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float10 fVar5;
  float local_14;
  undefined1 local_c [12];
  
  if ((DAT_0087a7f0 != 0) && (*(char *)(DAT_0087a7f0 + 0xe38) != '\0')) {
    local_14 = 1e+09;
    iVar3 = 0;
    piVar4 = &DAT_0087a96c;
    iVar2 = DAT_0087a7f0;
    do {
      if (((int *)*piVar4 != (int *)0x0) &&
         (iVar1 = *(int *)*piVar4, (*(byte *)(iVar1 + 0x94) & 1) == 0)) {
        fVar5 = (float10)FUN_005b3c50(iVar1 + 0x30,iVar2 + 0x80,0);
        iVar2 = DAT_0087a7f0;
        if ((float)fVar5 < local_14) {
          iVar3 = iVar1;
          local_14 = (float)fVar5;
        }
      }
      piVar4 = piVar4 + 1;
    } while ((int)piVar4 < 0x87a99c);
    if (iVar3 == 0) {
      *(undefined1 *)(iVar2 + 0xe38) = 0;
      FUN_004ba2d0(DAT_0087a7f0);
    }
    else if (local_14 < _DAT_007fc434 * _DAT_007fc434) {
      fVar5 = (float10)FUN_005becc0(iVar2 + 0x80,iVar3 + 0x30,local_c);
      FUN_006018c0(DAT_0087b9c8,_DAT_007fc438,_DAT_007fc43c,_DAT_007fc440,iVar3 + 0x30,local_c,
                   0xff808040,_DAT_007fc444,(float)fVar5);
      return;
    }
  }
  return;
}

