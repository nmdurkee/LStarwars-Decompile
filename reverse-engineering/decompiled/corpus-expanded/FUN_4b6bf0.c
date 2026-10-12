/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b6bf0; label: FUN_004b6bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b6bf0(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  float local_8;
  float local_4;
  
  local_4 = 0.0;
  local_8 = 8.0;
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) != 0) {
    uVar2 = FUN_0054a240(param_1,*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                         *(undefined4 *)(PTR_DAT_00802c54 + 0x11c));
    *(undefined1 *)(param_1 + 0xe3c) = uVar2;
  }
  if ((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (*(char *)(param_1 + 0x7b5) == '\x1b')) &&
     ((*(uint *)(param_1 + 0xe20) & 0x200) == 0)) {
    if (*(char *)(param_1 + 0x7b3) != '\x01') {
      FUN_00499500(param_1,0);
    }
    local_4 = 0.333;
  }
  if ((*(char *)(param_1 + 0x7b5) == '3') || ((*(uint *)(param_1 + 0xef0) & 0x400) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  iVar4 = FUN_00599960(param_1);
  if (iVar4 == 0) {
    if ((*(char *)(param_1 + 0x7b5) != '\x1c') && (*(char *)(param_1 + 0x7b5) != '3')) {
      if (local_4 == 0.0) {
        local_8 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x74) * 8.0;
        if ((*(short *)(param_1 + 0x1064) == DAT_007f1914) &&
           (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234)) {
          local_8 = local_8 + local_8;
        }
      }
      else {
        local_8 = local_4 * 8.0;
      }
    }
  }
  else {
    local_8 = *(float *)(param_1 + 0x778) * 8.0;
  }
  if (((*(uint *)(param_1 + 0xef0) & 0x8000) != 0) &&
     ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 1) == 0)) {
    *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + -0x8000;
  }
  if ((*(uint *)(param_1 + 0xef0) & 0x400) == 0) {
    if ((!bVar1) &&
       ((((local_4 != 0.0 ||
          ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 0xc) & 2) != 0)) ||
         ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x100) != 0)) ||
        (iVar4 = FUN_00599960(param_1), iVar4 != 0)))) {
      uVar5 = FUN_006e6b90(0);
      uVar5 = FUN_00550100(*(undefined2 *)(param_1 + 0x58),*(undefined2 *)(param_1 + 0x5a),uVar5);
      *(short *)(param_1 + 0x58) = (short)uVar5;
      uVar3 = FUN_00550070(*(undefined2 *)(param_1 + 0x27a),uVar5,0x41200000);
      *(undefined2 *)(param_1 + 0x5a) = *(undefined2 *)(param_1 + 0x58);
      goto LAB_004b6e3e;
    }
    uVar3 = FUN_00550070(*(undefined2 *)(param_1 + 0x58),*(undefined2 *)(param_1 + 0x5a),local_8);
  }
  else {
    uVar3 = *(undefined2 *)(param_1 + 0x5a);
  }
  *(undefined2 *)(param_1 + 0x58) = uVar3;
LAB_004b6e3e:
  *(undefined2 *)(param_1 + 0x27a) = uVar3;
  if (((*(int *)(param_1 + 0xcc4) != 0) && ((*(uint *)(param_1 + 0x1fc) & 0x1000) != 0)) &&
     ((*(char *)(param_1 + 0x28b) == '\0' && ((*(byte *)(param_1 + 0xe20) & 0x20) == 0)))) {
    FUN_004d24f0(param_1);
  }
  FUN_0058b210(param_1);
  iVar4 = FUN_0041aef0(param_1);
  if (((iVar4 != 0) && ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) == 0)) ||
     ((*(char *)(param_1 + 0xe43) == -1 ||
      (iVar4 = (int)*(short *)(&DAT_007fb0ea + *(char *)(param_1 + 0xe43) * 0x10), iVar4 == -1)))) {
    iVar4 = 0xdf;
  }
  FUN_00487dc0(param_1);
  FUN_004a28e0(0);
  *(undefined4 *)(param_1 + 0xd8c) = 0x3f800000;
  FUN_004a4ff0(iVar4);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004d3800(param_1,0,0);
  }
  FUN_004aa800(param_1);
  FUN_004b08d0(param_1);
  if ((DAT_0087b014 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087b014)) {
    FUN_004b6800(param_1);
    FUN_00415770(param_1);
  }
  if ((*(short *)(param_1 + 0x1064) == DAT_007f18bc) &&
     ((*(int *)(param_1 + 0x10ac) != 0 ||
      (FUN_005972c0(param_1,0xb), *(int *)(param_1 + 0x10ac) != 0)))) {
    FUN_00597380(param_1);
  }
  *(undefined4 *)(param_1 + 0x218) = *(undefined4 *)(param_1 + 0x21c);
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xffffbfff;
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x88);
  *(undefined1 *)(param_1 + 0x282) = *(undefined1 *)(param_1 + 0x281);
  *(undefined2 *)(param_1 + 0x1060) = *(undefined2 *)(param_1 + 0x27a);
  FUN_004ce740(param_1);
  if (*(char *)(param_1 + 0x280) != -1) {
    FUN_004a9450(param_1);
  }
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x68);
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xfffffbff;
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x70);
  *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xfffffffb | 0x10000;
  *(undefined4 *)(param_1 + 0xf18) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0xf1c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined2 *)(param_1 + 0x106e) = 0xffff;
  *(undefined4 *)(param_1 + 0xf20) = *(undefined4 *)(param_1 + 0x70);
  FUN_0062b040(param_1);
  FUN_0055d2b0(param_1);
  FUN_0042fcf0(param_1);
  return;
}

