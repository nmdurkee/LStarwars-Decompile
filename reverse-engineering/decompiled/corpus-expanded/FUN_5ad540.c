/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ad540; label: FUN_005ad540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ad540(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if (*(char *)(param_2 + 0x12e) < '\x01') {
    return 0;
  }
  if (param_5 == -1) {
    *(undefined1 *)(param_2 + 0x12e) = 0;
  }
  else {
    *(char *)(param_2 + 0x12e) = *(char *)(param_2 + 0x12e) - (char)param_5;
  }
  if (*(char *)(param_2 + 0x12e) < '\x01') {
    *(undefined1 *)(param_2 + 0x12e) = 0;
    iVar2 = FUN_0054fa60();
    if (iVar2 < 0x8000) {
      uVar3 = 0x3ecccccd;
    }
    else {
      uVar3 = 0xbecccccd;
    }
    FUN_00549de0(PTR_DAT_008021b4,uVar3,2,0);
    FUN_0054a910(0x3f800000,0,0,0);
    if ((*(uint *)(param_2 + 0x108) & 0x2000) == 0) {
      *(ushort *)(param_2 + 0x13a) = *(ushort *)(param_2 + 0x13a) | 0x20;
      FUN_005a15e0(*(undefined4 *)(param_2 + 0x18),0);
      if (*(int *)(param_2 + 0x18) != 0) {
        for (puVar1 = *(undefined4 **)(*(int *)(param_2 + 0x18) + 0x18); puVar1 != (undefined4 *)0x0
            ; puVar1 = (undefined4 *)*puVar1) {
          if (*(char *)(puVar1[9] + 1) == '\x03') {
            FUN_005cfc00(puVar1 + 1,1);
          }
        }
      }
    }
    else {
      *(ushort *)(param_2 + 0x13a) = *(ushort *)(param_2 + 0x13a) | 0x10;
    }
    if (*(short *)(param_2 + 0x124) != -1) {
      uVar3 = FUN_005cf9e0(*(int *)(param_2 + 0x1c) + 4);
      FUN_0056a8c0(param_1,(int)*(short *)(param_2 + 0x124),uVar3);
    }
    local_24 = *(undefined4 *)(param_2 + 0x24);
    local_20 = *(undefined4 *)(param_2 + 0x28);
    local_1c = *(undefined4 *)(param_2 + 0x2c);
    FUN_005a0c20(*(undefined4 *)(param_2 + 0x18),&local_24,0,2,1,1);
    if (*(short *)(param_2 + 0x138) != -1) {
      FUN_005478a0((int)*(short *)(param_2 + 0x138),&local_24,0,0);
    }
    if ((*(short *)(param_2 + 0x10c) != 0) &&
       (((*(ushort *)(param_2 + 0x13a) & 0x400) == 0 ||
        ((*(uint *)(param_2 + 0x108) & 0x40000) != 0)))) {
      FUN_005b37d0(local_c,&local_24,param_2 + 0x114);
      FUN_005b35a0(local_18,&DAT_00802500,*(undefined2 *)(param_2 + 0x110));
      FUN_005b3620(local_18,local_18,*(undefined2 *)(param_2 + 0x112));
      FUN_0046d270(*(undefined2 *)(param_2 + 0x10c),0,0,0,local_c,local_18,0x40000000,0xffffffff,
                   *(undefined4 *)(param_2 + 0x120),0x49f42400,0,1,0);
      *(ushort *)(param_2 + 0x13a) = *(ushort *)(param_2 + 0x13a) | 0x400;
    }
    if ((((*(uint *)(param_2 + 0x108) & 0x4000) != 0) && ((*(uint *)(param_2 + 0x108) & 0x10) == 0))
       && (DAT_00803988 != -1)) {
      FUN_00576960(DAT_00803988);
      return 1;
    }
  }
  else if ((param_4 != -1) && ((*(byte *)((&DAT_0093d7f0)[param_4] + 0x1fc) & 0x80) != 0)) {
    FUN_0054a8a0(**(undefined4 **)((&DAT_0093d7f0)[param_4] + 0xca4),0x3dcccccd,0);
  }
  return 1;
}

