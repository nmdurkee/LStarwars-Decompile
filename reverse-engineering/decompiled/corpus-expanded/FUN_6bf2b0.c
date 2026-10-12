/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bf2b0; label: FUN_006bf2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bf2b0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x28))();
    uStack_20 = *puVar1;
    uStack_1c = puVar1[1];
    uStack_18 = puVar1[2];
    fVar2 = (float10)(**(code **)(**(int **)(in_ECX + 0x10) + 0x14))();
    FUN_006ba6a0(0);
    FUN_006bb070(&uStack_20,(float)fVar2,0x3f800000,0x80808080);
    if (DAT_02973a60 != 0) {
      if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
        FUN_006009c0();
      }
      DAT_02973a60 = 0;
    }
  }
  return;
}

