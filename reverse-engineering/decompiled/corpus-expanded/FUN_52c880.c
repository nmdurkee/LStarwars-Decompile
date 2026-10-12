/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52c880; label: FUN_0052c880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0052c880(undefined4 param_1,int param_2,undefined4 param_3,float param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  float10 fVar5;
  float local_4;
  
  iVar3 = (int)param_4;
  local_4 = 0.0;
  if ((param_4 != 0.0) && (param_2 != 0)) {
    for (iVar4 = FUN_004f1440(param_2); iVar4 != 0; iVar4 = FUN_004f1460(param_2,iVar4)) {
      if (*(int *)(iVar4 + 0x1c) == 0) goto switchD_0052c9ad_default;
      pcVar1 = *(code **)(*(int *)(iVar4 + 0x1c) + 4);
      if (pcVar1 != (code *)0x0) {
        fVar5 = (float10)(*pcVar1)(param_1,iVar3,param_3,*(undefined4 *)(iVar4 + 0x14),
                                   *(undefined4 *)(iVar4 + 0x18));
        local_4 = (float)fVar5;
      }
      if ((*(int *)(iVar4 + 0x28) == 0) ||
         (iVar2 = *(int *)(*(int *)(iVar4 + 0x28) + 0x1c), iVar2 == 0)) {
        if ((*(ushort *)(iVar4 + 0xe) & 8) == 0) {
          if ((*(ushort *)(iVar4 + 0xe) & 4) == 0) {
            param_4 = *(float *)(iVar4 + 8);
          }
          else {
            param_4 = *(float *)(iVar3 + 0x14 + *(char *)(iVar4 + 0xd) * 4);
          }
        }
        else {
          if (*(char *)(iVar3 + 0x38 + in_EAX * 0x14) != '\0') {
            fVar5 = (float10)FUN_00514920(param_3,iVar3,*(undefined4 *)(iVar4 + 0x10));
            *(float *)(iVar3 + ((int)*(char *)(iVar4 + 0xd) + in_EAX * 5 + 10) * 4) = (float)fVar5;
          }
          param_4 = *(float *)(iVar3 + ((int)*(char *)(iVar4 + 0xd) + in_EAX * 5 + 10) * 4);
        }
      }
      else {
        pcVar1 = *(code **)(iVar2 + 4);
        param_4 = local_4;
        if (pcVar1 != (code *)0x0) {
          fVar5 = (float10)(*pcVar1)(param_1,iVar3,param_3,*(undefined4 *)(iVar4 + 0x14),
                                     *(undefined4 *)(iVar4 + 0x18));
          param_4 = (float)fVar5;
        }
      }
      switch(*(undefined1 *)(iVar4 + 0xc)) {
      case 0:
        if (param_4 != local_4) break;
LAB_0052ca10:
        if ((*(byte *)(iVar4 + 0xe) & 1) == 0) {
          FUN_0052c800(param_2,param_3,iVar3);
          *(undefined1 *)(iVar3 + 0x38 + in_EAX * 0x14) = 0;
          return iVar4;
        }
        goto LAB_0052ca1a;
      case 1:
        if (local_4 < param_4) goto LAB_0052ca10;
        break;
      case 2:
        if (param_4 < local_4) goto LAB_0052ca10;
        break;
      case 3:
        if (local_4 <= param_4) goto LAB_0052ca10;
        break;
      case 4:
        if (param_4 < local_4 != (param_4 == local_4)) goto LAB_0052ca10;
        break;
      case 5:
        if (param_4 != local_4) goto LAB_0052ca10;
      }
switchD_0052c9ad_default:
      while ((*(byte *)(iVar4 + 0xe) & 1) != 0) {
        iVar4 = FUN_004f1460(param_2,iVar4);
        if (iVar4 == 0) goto LAB_0052ca2e;
        if ((*(char *)(iVar3 + 0x38 + in_EAX * 0x14) != '\0') && ((*(byte *)(iVar4 + 0xe) & 8) != 0)
           ) {
          iVar2 = in_EAX * 5 + 10;
          fVar5 = (float10)FUN_00514920(param_3,iVar3,*(undefined4 *)(iVar4 + 0x10));
          *(float *)(iVar3 + (*(char *)(iVar4 + 0xd) + iVar2) * 4) = (float)fVar5;
          *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar3 + (*(char *)(iVar4 + 0xd) + iVar2) * 4)
          ;
        }
      }
LAB_0052ca1a:
    }
LAB_0052ca2e:
    FUN_0052c800(param_2,param_3,iVar3);
    *(undefined1 *)(iVar3 + 0x38 + in_EAX * 0x14) = 0;
  }
  return 0;
}

