/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635420; label: FUN_00635420
 */

void FUN_00635420(int param_1,int param_2)

{
  int in_ECX;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(in_ECX + 4);
  local_8 = param_1;
  local_4 = 0;
  FUN_006c94a0(&local_c,*(undefined4 *)(param_1 + 8));
  if (*(int *)(param_1 + 0x14) == 1) {
    FUN_00623e00(param_1 + 0x20,*(undefined4 *)(param_1 + 0x1c),
                 *(uint *)(param_1 + 8) & 0xffffff | 0x80000000,0x10,0);
    if (param_2 != 0) {
      FUN_00623fc0(param_1 + 0x20,*(undefined4 *)(param_1 + 0x1c),0xffffffff,0);
    }
  }
  return;
}

