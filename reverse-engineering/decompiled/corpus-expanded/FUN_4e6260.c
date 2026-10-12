/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e6260; label: FUN_004e6260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e6260(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  byte bVar5;
  
  bVar5 = 0;
  piVar4 = &DAT_0088a414;
  do {
    iVar3 = *piVar4;
    if ((iVar3 != 0) && (DAT_00951b50 == 0)) {
      if (piVar4[1] == 0) {
        iVar3 = FUN_0058ecf0(iVar3);
        if (iVar3 != 0) {
          FUN_00590690(*piVar4);
          FUN_00590c10(*piVar4,0,0);
          FUN_005900a0(*piVar4,0);
        }
      }
      else {
        iVar3 = FUN_0058ecf0(iVar3);
        if ((iVar3 != 0) && ((char)piVar4[10] != '\0')) {
          FUN_0041f6d0(piVar4 + 2,0,0);
          FUN_005900a0(*piVar4,0);
          puVar2 = PTR_DAT_00802c54;
          *(undefined1 *)(piVar4 + 10) = 0;
          *(uint *)(*(int *)(puVar2 + 0x130) + 0x281c) =
               *(uint *)(*(int *)(puVar2 + 0x130) + 0x281c) & ~(1 << (bVar5 & 0x1f));
        }
      }
    }
    iVar3 = piVar4[1];
    if (iVar3 == 0) {
      return;
    }
    if (DAT_00951b50 != 0) {
      return;
    }
    iVar1 = *(int *)(iVar3 + 0xcd0);
    if (iVar1 == 0) {
      if (*(int *)(iVar3 + 0xea8) == 0) {
        *(code **)(iVar3 + 0xea8) = FUN_004e5f10;
      }
    }
    else if (*(int *)(iVar1 + 0xea8) == 0) {
      *(code **)(iVar1 + 0xea8) = FUN_004e5f10;
    }
    piVar4 = piVar4 + 0xc;
    bVar5 = bVar5 + 1;
  } while ((int)piVar4 < 0x88a4d4);
  return;
}

