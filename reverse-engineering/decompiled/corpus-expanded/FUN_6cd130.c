/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cd130; label: FUN_006cd130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cd130(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_30 [16];
  undefined1 local_20 [28];
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 0x74) == -1) {
    FUN_006c5a20(param_1);
  }
  FUN_005d6e10(((float)*(int *)(iVar1 + 0x1c) * 0.5 + (float)*(int *)(iVar1 + 0x14)) / 640.0,
               ((float)*(int *)(iVar1 + 0x20) * 0.125 + (float)*(int *)(iVar1 + 0x18)) / 448.0,
               local_20,local_30,0);
  FUN_006c8760(8,DAT_02973ab8,local_30,0);
  FUN_006ba6a0(0);
  FUN_006ba7d0(local_20,local_30,in_ECX + 0x2c);
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00626b50(iVar1);
  }
  if ((*(int *)(iVar1 + 8) != 0) &&
     (piVar2 = *(int **)(*(int *)(iVar1 + 8) + 0xc), piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 0xc))();
  }
  return;
}

