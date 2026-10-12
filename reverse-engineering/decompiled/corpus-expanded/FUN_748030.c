/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748030; label: FUN_00748030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748030(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  int *local_8;
  int local_4;
  
  local_4 = 0;
  if (0 < *(int *)(in_ECX + 0x89c)) {
    local_8 = (int *)(in_ECX + 0x4b4);
    do {
      piVar1 = (int *)*local_8;
      if ((*piVar1 == 0x1004) && (0 < piVar1[8])) {
        uVar2 = FUN_00746a00(piVar1);
        FUN_007486b0("#define ");
        FUN_007486b0(uVar2);
        FUN_007486b0(&DAT_0076aa4c);
        FUN_00747320(uVar2,0,0);
        FUN_007486b0((&PTR_s_undefined_008543d0)[piVar1[1]]);
        FUN_007486b0(&DAT_007596f8);
        FUN_007486b0(piVar1[3]);
        if (piVar1[4] != 1) {
          FUN_007486b0(&DAT_0075c044);
          uVar2 = FUN_00746590();
          FUN_007486b0(uVar2);
        }
        FUN_007486b0(&DAT_007e9630);
      }
      local_8 = local_8 + 1;
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(in_ECX + 0x89c));
  }
  return;
}

