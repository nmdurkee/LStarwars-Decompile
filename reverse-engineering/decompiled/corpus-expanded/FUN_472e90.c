/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x472e90; label: FUN_00472e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00472e90(int param_1,undefined4 param_2,float param_3)

{
  int *piVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  char local_4;
  
  piVar1 = *(int **)(param_1 + 0x5074);
  if ((piVar1 != (int *)0x0) && (iVar5 = 0, 0 < *piVar1)) {
    iVar4 = 0;
    do {
      iVar6 = piVar1[3] + iVar4;
      if (0.0 < *(float *)(piVar1[3] + 0x84 + iVar4)) {
        fVar2 = *(float *)(iVar6 + 0x84) - _DAT_00925018;
        *(float *)(iVar6 + 0x84) = fVar2;
        if ((fVar2 < 0.0 != (fVar2 == 0.0)) && (*(char *)(iVar6 + 0x5f) == '\0')) {
          if (*(char *)(iVar6 + 0x5e) == '\0') {
            fVar7 = (float10)FUN_005b9ef0(&DAT_00802538);
            local_4 = (char)(int)ROUND(fVar7 * (float10)-4.0);
            *(char *)(iVar6 + 0x5f) = '\x01' - local_4;
          }
          else {
            *(char *)(iVar6 + 0x5f) = *(char *)(iVar6 + 0x5e);
          }
          *(undefined4 *)(iVar6 + 0x84) = 0x3f800000;
        }
      }
      if ((((*(byte *)(iVar6 + 99) & 1) != 0) && ('\0' < *(char *)(iVar6 + 0x60))) &&
         (fVar2 = *(float *)(iVar6 + 0x8c) + param_3, *(float *)(iVar6 + 0x8c) = fVar2,
         *(float *)(iVar6 + 0x88) < fVar2)) {
        cVar3 = *(char *)(iVar6 + 0x60) + '\x01';
        *(char *)(iVar6 + 0x60) = cVar3;
        if (cVar3 == '\x02') {
          FUN_00681f40("SwLever",iVar6 + 0x50);
        }
        *(undefined4 *)(iVar6 + 0x8c) = 0;
        if ('\x06' < *(char *)(iVar6 + 0x60)) {
          *(byte *)(iVar6 + 99) = *(byte *)(iVar6 + 99) & 0xfe;
          *(undefined4 *)(iVar6 + 0x88) = 0;
          *(undefined1 *)(iVar6 + 0x60) = 0;
          *(undefined4 *)(iVar6 + 0x84) = 0x3f19999a;
          *(undefined4 *)(iVar6 + 0x94) = 0;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xa0;
    } while (iVar5 < *piVar1);
  }
  return;
}

