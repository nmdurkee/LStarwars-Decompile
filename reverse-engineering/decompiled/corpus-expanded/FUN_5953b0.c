/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x5953b0; label: FUN_005953b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005953b0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  switch(param_1) {
  case 0:
    *(undefined4 *)(in_ECX + 0x80c) = param_2;
    return;
  case 1:
    *(undefined4 *)(in_ECX + 0x810) = param_2;
    return;
  case 2:
    *(undefined4 *)(in_ECX + 0x814) = param_2;
    return;
  case 3:
    *(undefined4 *)(in_ECX + 0x818) = param_2;
    return;
  case 6:
  case 7:
    *(undefined4 *)(in_ECX + 0x110) = param_2;
    return;
  case 8:
    *(undefined4 *)(in_ECX + 0x490) = param_2;
    return;
  case 9:
  case 10:
  case 0xb:
    *(undefined4 *)(in_ECX + 0x104) = param_2;
    return;
  case 0xc:
  case 0xd:
  case 0xe:
    *(undefined4 *)(in_ECX + 0x100) = param_2;
    return;
  case 0xf:
  case 0x10:
    *(undefined4 *)(in_ECX + 0x484) = param_2;
    return;
  case 0x11:
  case 0x12:
    *(undefined4 *)(in_ECX + 0x480) = param_2;
    return;
  case 0x13:
    *(undefined4 *)(in_ECX + 0x81c) = param_2;
    return;
  case 0x14:
    *(undefined4 *)(in_ECX + 0x820) = param_2;
  }
  return;
}

