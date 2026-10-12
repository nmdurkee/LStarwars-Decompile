/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x747760; label: FUN_00747760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00747760(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int in_ECX;
  int *local_4c;
  int local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_4c;
  FUN_007486b0("struct VertexInput { \r\n");
  local_48 = 0;
  if (0 < *(int *)(in_ECX + 0x89c)) {
    local_4c = (int *)(in_ECX + 0x4b4);
    do {
      piVar1 = (int *)*local_4c;
      if ((*piVar1 == 0x2010) && (0 < piVar1[8])) {
        if (piVar1[2] < 0) {
          local_44[0] = '\0';
        }
        else {
          _sprintf(local_44,"[%d] ",piVar1[2]);
        }
        uVar3 = FUN_00746a00(piVar1);
        FUN_007486b0("\t#define ");
        FUN_007486b0(uVar3);
        FUN_007486b0(&DAT_0076aa4c);
        FUN_00747320(uVar3,0,0);
        puVar2 = (&PTR_s_undefined_008543d0)[piVar1[1]];
        FUN_007486b0(&DAT_00775790);
        FUN_007486b0(puVar2);
        FUN_007486b0(&DAT_007596f8);
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(local_44);
        FUN_007486b0(&DAT_00759700);
        uVar3 = FUN_00746590();
        FUN_007486b0(uVar3);
        FUN_007486b0(&DAT_007e9630);
      }
      local_4c = local_4c + 1;
      local_48 = local_48 + 1;
    } while (local_48 < *(int *)(in_ECX + 0x89c));
  }
  FUN_007486b0(&DAT_007e9650);
  __security_check_cookie(local_4 ^ (uint)&local_4c);
  return;
}

