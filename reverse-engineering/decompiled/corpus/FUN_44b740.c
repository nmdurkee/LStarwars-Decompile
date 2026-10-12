/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44b740; label: FUN_0044b740
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0044b740(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 **ppuVar4;
  float10 fVar5;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  float local_120;
  float local_11c;
  float local_118;
  undefined1 local_114 [12];
  undefined1 *local_108 [5];
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 *local_e4;
  undefined4 local_dc;
  code *local_c8;
  undefined4 local_7c;
  undefined1 local_40 [64];
  
  if (param_6 != 0) {
    iVar2 = 0;
    local_12c = 0;
    local_128 = 0;
    local_124 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_0075782c);
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757898);
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757894);
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757890);
              if (iVar1 != 0) {
                fVar5 = (float10)FUN_005147c0(param_2,iVar1 + 2);
                local_118 = (float)fVar5;
              }
            }
            else {
              fVar5 = (float10)FUN_005147c0(param_2,iVar1 + 2);
              local_11c = (float)fVar5;
            }
          }
          else {
            fVar5 = (float10)FUN_005147c0(param_2,iVar1 + 2);
            local_120 = (float)fVar5;
          }
        }
        else {
          FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&local_12c,iVar1 + 5,1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
    iVar2 = FUN_005cfac0(&local_12c);
    if (iVar2 != 0) {
      FUN_0049f630(local_114,&local_120,DAT_0093d810 + 0x80,DAT_0093d810 + 0x68,_DAT_007fb088,
                   _DAT_007fb084);
      FUN_005b4500(local_40,&local_120);
      puVar3 = &DAT_00810210;
      ppuVar4 = local_108;
      for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppuVar4 = (undefined1 *)*puVar3;
        puVar3 = puVar3 + 1;
        ppuVar4 = ppuVar4 + 1;
      }
      local_f4 = 0x3dcccccd;
      local_f0 = 0x3dcccccd;
      local_ec = _DAT_007fb084;
      local_7c = _DAT_00925018;
      local_108[0] = local_40;
      local_108[2] = local_114;
      local_e4 = &local_12c;
      local_dc = 0x29b;
      local_c8 = FUN_0042cf20;
      FUN_0064d270(local_108);
      FUN_0054a850(**(undefined4 **)(DAT_0093d810 + 0xca4),0x3f000000,0);
    }
    return 1;
  }
  return 1;
}

