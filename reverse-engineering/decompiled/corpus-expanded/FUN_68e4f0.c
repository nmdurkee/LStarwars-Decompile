/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68e4f0; label: FUN_0068e4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068e4f0(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar6 = &DAT_02924b5c;
  do {
    piVar1 = puVar6 + 1;
    if (puVar6[1] != -1) {
      *piVar1 = -1;
      uVar4 = FUN_00658330(puVar6 + 6,0,0);
      *puVar6 = uVar4;
      FUN_00684ee0(piVar1,uVar4,puVar6[-3],puVar6[-2],puVar6[-1]);
      if (*piVar1 == -1) {
        *piVar1 = 99999;
      }
      else {
        *(undefined1 *)(*piVar1 * 0x330 + 0x2f9 + DAT_029620a4) = 0;
        FUN_00684640(*piVar1,*(undefined2 *)(puVar6 + 2),*(undefined2 *)((int)puVar6 + 10));
        FUN_006846a0(*piVar1,*(undefined2 *)(puVar6 + 3),*(undefined2 *)((int)puVar6 + 0xe),
                     *(undefined2 *)(puVar6 + 4));
        FUN_00655c30(*piVar1 * 0x330 + DAT_029620a4,puVar6[5]);
        uVar4 = puVar6[0xc];
        uVar3 = puVar6[0xb];
        if (*piVar1 != -1) {
          iVar5 = *piVar1 * 0x330;
          *(undefined4 *)(iVar5 + 0x2d0 + DAT_029620a4) = puVar6[10];
          *(undefined4 *)(iVar5 + 0x2d4 + DAT_029620a4) = uVar3;
          *(undefined4 *)(iVar5 + 0x2d8 + DAT_029620a4) = uVar4;
        }
        uVar4 = puVar6[0xe];
        uVar3 = puVar6[0xf];
        uVar2 = *(undefined2 *)((int)puVar6 + 0x36);
        if (*piVar1 != -1) {
          iVar5 = *piVar1 * 0x330;
          *(undefined2 *)(iVar5 + 0x2dc + DAT_029620a4) = *(undefined2 *)(puVar6 + 0xd);
          *(undefined2 *)(iVar5 + 0x2de + DAT_029620a4) = uVar2;
          *(undefined4 *)(iVar5 + 0x2e0 + DAT_029620a4) = uVar4;
          *(undefined4 *)(iVar5 + 0x2e4 + DAT_029620a4) = uVar3;
        }
        FUN_00684720(*piVar1,*(undefined1 *)((int)puVar6 + 0x47),*(undefined2 *)(puVar6 + 0x12),
                     *(undefined2 *)((int)puVar6 + 0x4a));
        if (*piVar1 != -1) {
          *(undefined2 *)(*piVar1 * 0x330 + 0x2f0 + DAT_029620a4) = *(undefined2 *)(puVar6 + 0x10);
        }
        FUN_00655f30(*piVar1,*(undefined4 *)(&DAT_02947bdc + *(char *)((int)puVar6 + 0x45) * 4));
      }
      *(undefined4 *)(&DAT_02948eb0 + *(char *)((int)puVar6 + 0x45) * 4) = 1;
    }
    puVar6 = puVar6 + 0x16;
  } while ((int)puVar6 < 0x292fb5c);
  DAT_00810ad8 = 0xffffffff;
  FUN_00661f60(0x3f800000);
  return;
}

