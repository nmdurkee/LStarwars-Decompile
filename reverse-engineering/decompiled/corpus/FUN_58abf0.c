/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58abf0; label: FUN_0058abf0
 */

void FUN_0058abf0(undefined4 param_1,uint *param_2)

{
  short *psVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  float10 fVar6;
  
  DAT_009553dc = 0;
  DAT_009553e0 = 0;
  iVar3 = FUN_004fc860(param_1);
  if (iVar3 == 0) {
    FUN_0058aae0(param_1);
    return;
  }
  DAT_009553dc = *param_2 + 3 & 0xfffffffc;
  *param_2 = DAT_009553dc;
  iVar4 = FUN_004fc5b0(iVar3);
  while( true ) {
    if (iVar4 == 0) {
      FUN_004fa300(iVar3);
      if (0 < DAT_009553e0) {
        *param_2 = DAT_009553e0 * 0x10 + DAT_009553dc;
        return;
      }
      DAT_009553dc = 0;
      return;
    }
    iVar4 = FUN_004f7fb0(iVar3);
    if ((iVar4 != 0) &&
       (iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"specialmove_start"), iVar4 == 0))
    break;
LAB_0058ae75:
    iVar4 = FUN_004fc5b0(iVar3);
  }
  fVar6 = (float10)0;
  psVar5 = (short *)(DAT_009553e0 * 0x10 + DAT_009553dc);
  *(undefined1 *)((int)psVar5 + 5) = 0xff;
  psVar5[4] = -1;
  psVar1 = psVar5 + 3;
  psVar2 = psVar5 + 2;
  *(char *)psVar2 = -1;
  *psVar5 = -1;
  psVar5[1] = -1;
  *psVar1 = -1;
  psVar5[5] = 0;
  do {
    *(float *)(psVar5 + 6) = (float)fVar6;
    while( true ) {
      while( true ) {
        while( true ) {
          iVar4 = FUN_004fc5b0(iVar3);
          if ((iVar4 == 0) || (iVar4 = FUN_004f7fb0(iVar3), iVar4 == 0)) goto LAB_0058ae75;
          iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"specialmove_end");
          if (iVar4 == 0) {
            if (((((char)*psVar2 != -1) || (psVar5[1] != -1)) && (*psVar5 != -1)) &&
               (((*(char *)((int)psVar5 + 5) != -1 || (*psVar1 != -1)) && (psVar5[4] != -1)))) {
              DAT_009553e0 = DAT_009553e0 + 1;
            }
            goto LAB_0058ae75;
          }
          iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"attacker");
          if (iVar4 != 0) break;
          FUN_0058ab10(psVar5 + 1,psVar2);
        }
        iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"victim");
        if (iVar4 != 0) break;
        FUN_0058ab10(psVar1,(char *)((int)psVar5 + 5));
      }
      iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"distance_apart");
      if (iVar4 == 0) break;
      iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"kill_victim_at_end");
      if (iVar4 == 0) {
        psVar5[5] = psVar5[5] | 2;
      }
      else {
        iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"kill_victim_at_release");
        if (iVar4 == 0) {
          psVar5[5] = psVar5[5] | 4;
        }
        else {
          iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"flash_victim_at_attack_end");
          if (iVar4 == 0) {
            psVar5[5] = psVar5[5] | 8;
          }
          else {
            iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"throw_kill_parts_up");
            if (iVar4 == 0) {
              psVar5[5] = psVar5[5] | 0x10;
            }
            else {
              iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"can_always_do");
              if (iVar4 == 0) {
                psVar5[5] = psVar5[5] | 1;
              }
            }
          }
        }
      }
    }
    fVar6 = (float10)FUN_004f8100(iVar3);
  } while( true );
}

