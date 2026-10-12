/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x418fb0; label: FUN_00418fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00418fb0(int param_1,int param_2,int param_3)

{
  undefined4 *in_EAX;
  int in_ECX;
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if ((((unaff_EDI == 0) && (param_1 == 0)) && (param_2 == 0)) && (param_3 == 0)) {
    return;
  }
  if (*(short *)(in_ECX + 0x1064) == DAT_007f1880) {
    *unaff_ESI = 0x12;
    *in_EAX = 0x12;
  }
  else if ((*(short *)(in_ECX + 0x1064) == DAT_007f1a08) &&
          (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x13e) != '\0')) {
    *unaff_ESI = 0x13;
    *in_EAX = 0x13;
  }
  else {
    *unaff_ESI = 0x11;
    *in_EAX = 0x11;
  }
  if (unaff_EDI == 0) {
    if (param_1 == 0) {
      if (param_2 == 0) {
        if (param_3 == 0) {
          return;
        }
        if (*(char *)(in_ECX + 0x28b) != '\0') {
          return;
        }
        in_EAX[1] = 0x6b;
        uVar1 = 0x6c;
      }
      else {
        if (*(char *)(in_ECX + 0x28b) != '\0') {
          return;
        }
        in_EAX[1] = 0x69;
        uVar1 = 0x6a;
      }
    }
    else {
      if (*(char *)(in_ECX + 0x28b) != '\0') {
        return;
      }
      in_EAX[1] = 0x67;
      uVar1 = 0x68;
    }
  }
  else if (*(short *)(in_ECX + 0x1064) == DAT_007f1880) {
    if (*(char *)(in_ECX + 0x28b) != '\0') {
      return;
    }
    in_EAX[1] = 0x6d;
    uVar1 = 0x6e;
  }
  else {
    if (*(char *)(in_ECX + 0x28b) != '\0') {
      return;
    }
    in_EAX[1] = 0x65;
    uVar1 = 0x66;
  }
  in_EAX[2] = uVar1;
  if ((*(uint *)(in_ECX + 0xe20) & 0x80000) != 0) {
    in_EAX[3] = uVar1;
  }
  return;
}

