/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x7478c0; label: FUN_007478c0
 */

void FUN_007478c0(void)

{
  int *piVar1;
  undefined *puVar2;
  char **ppcVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  char *pcVar8;
  int local_a8;
  int local_a4;
  int *local_a0;
  int local_9c;
  int local_98;
  char **local_94;
  char *local_90;
  char *local_8c;
  char *local_88;
  char *local_84;
  char *local_80 [4];
  char *local_70 [12];
  int local_40;
  undefined1 local_3c [60];
  
  local_a4 = 0;
  local_a8 = 0;
  bVar4 = false;
  local_40 = 0;
  _memset(local_3c,0,0x3c);
  local_80[0] = "texcoord0";
  local_80[1] = "texcoord1";
  local_80[2] = "texcoord2";
  local_80[3] = "texcoord3";
  local_70[0] = "texcoord4";
  local_70[1] = "texcoord5";
  local_70[2] = "texcoord6";
  local_70[3] = "texcoord7";
  local_70[4] = "texcoord8";
  local_70[5] = "texcoord9";
  local_70[6] = "texcoord10";
  local_70[7] = "texcoord11";
  local_70[8] = "texcoord12";
  local_70[9] = "texcoord13";
  local_70[10] = "texcoord14";
  local_70[0xb] = "texcoord15";
  FUN_007486b0("struct VertexOutput { \r\n");
  local_98 = 0;
  if (0 < *(int *)(in_ECX + 0x89c)) {
    local_a0 = (int *)(in_ECX + 0x4b4);
    do {
      piVar1 = (int *)*local_a0;
      if ((*piVar1 != 0x3008) || (piVar1[8] < 1)) goto switchD_00747a0c_caseD_3;
      uVar5 = FUN_00746a00(piVar1);
      FUN_007486b0("\t#define ");
      FUN_007486b0(uVar5);
      FUN_007486b0(&DAT_0076aa4c);
      FUN_00747320(uVar5,0,0);
      iVar6 = piVar1[4];
      switch(iVar6) {
      case 2:
        FUN_007486b0("\t#define ");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(" vout._");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(&DAT_0076aa4c);
        FUN_007486b0("\tfloat4 _");
        FUN_007486b0(piVar1[3]);
        pcVar8 = ": POSITION;\r\n";
        break;
      default:
        goto switchD_00747a0c_caseD_3;
      case 4:
        FUN_007486b0("\t#define ");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(" vout._");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(&DAT_0076aa4c);
        FUN_007486b0("\tfloat4 _");
        FUN_007486b0(piVar1[3]);
        pcVar8 = ": VPOS;\r\n";
        goto LAB_00747cd9;
      case 9:
        if (*(int *)(in_ECX + 0x984) <= local_a4) goto switchD_00747a0c_caseD_d;
        FUN_007486b0("\t#define ");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(" vout._");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(&DAT_0076aa4c);
        puVar2 = (&PTR_s_undefined_008543d0)[piVar1[1]];
        FUN_007486b0(&DAT_00775790);
        FUN_007486b0(puVar2);
        FUN_007486b0(&DAT_007e96d4);
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(": COLOR");
        FUN_007486e0(local_a4);
        local_a4 = local_a4 + 1;
        pcVar8 = ";\r\n";
        break;
      case 0xc:
        FUN_007486b0("\t#define ");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(" vout._");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(&DAT_0076aa4c);
        FUN_007486b0("\tfloat _");
        FUN_007486b0(piVar1[3]);
        pcVar8 = ": FOG;\r\n";
        break;
      case 0xd:
switchD_00747a0c_caseD_d:
        iVar6 = 0;
        local_9c = -1;
        if (0 < *(int *)(in_ECX + 0x980)) {
          do {
            if (*(int *)(local_3c + iVar6 * 4 + -4) == 0) {
              *(int *)(local_3c + iVar6 * 4 + -4) =
                   *(int *)(local_3c + iVar6 * 4 + -4) + *(int *)(&DAT_007e9458 + piVar1[1] * 4);
              local_a8 = local_a8 + 1;
              local_9c = iVar6;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(in_ECX + 0x980));
        }
        iVar7 = *(int *)(&DAT_007e9458 + piVar1[1] * 4);
        FUN_007486b0("\t#define ");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(" vout.");
        FUN_007486b0(local_80[local_9c]);
        iVar6 = *(int *)(local_3c + local_9c * 4 + -4) - iVar7;
        goto LAB_00747bb4;
      case 0xe:
      case 0xf:
        iVar7 = *(int *)(&DAT_007e9458 + piVar1[1] * 4);
        local_80[iVar6 + 2] = local_80[iVar6 + 2] + iVar7;
        local_a8 = local_a8 + 1;
        local_94 = local_80 + iVar6 + 2;
        FUN_007486b0("\t#define ");
        FUN_007486b0(piVar1[3]);
        FUN_007486b0(" vout.");
        FUN_007486b0(*(undefined4 *)(&stack0xffffff48 + iVar6 * 4));
        iVar6 = (int)*local_94 - iVar7;
LAB_00747bb4:
        uVar5 = FUN_00746950(iVar6,iVar7);
        FUN_007486b0(uVar5);
        pcVar8 = "\r\n";
LAB_00747cd9:
        FUN_007486b0(pcVar8);
        FUN_00747320(piVar1[3],piVar1[3],0);
        goto switchD_00747a0c_caseD_3;
      }
      FUN_007486b0(pcVar8);
      FUN_00747320(piVar1[3],piVar1[3],0);
      local_a8 = local_a8 + 1;
switchD_00747a0c_caseD_3:
      local_a0 = local_a0 + 1;
      local_98 = local_98 + 1;
    } while (local_98 < *(int *)(in_ECX + 0x89c));
  }
  local_98 = 0;
  if (0 < *(int *)(in_ECX + 0x89c)) {
    local_a0 = (int *)(in_ECX + 0x4b4);
    do {
      ppcVar3 = (char **)*local_a0;
      local_94 = ppcVar3;
      if (((*ppcVar3 == (char *)0x3008) && (0 < (int)ppcVar3[8])) && (ppcVar3[4] == (char *)0x1)) {
        local_a4 = -1;
        if (bVar4) {
LAB_00747db7:
          iVar6 = 0;
          do {
            if (*(int *)(&DAT_007e9458 + (int)ppcVar3[1] * 4) <=
                4 - *(int *)(local_3c + iVar6 * 4 + -4)) {
              *(int *)(local_3c + iVar6 * 4 + -4) =
                   *(int *)(local_3c + iVar6 * 4 + -4) +
                   *(int *)(&DAT_007e9458 + (int)ppcVar3[1] * 4);
              local_a4 = iVar6;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 0x10);
        }
        else {
          iVar6 = 0;
          if (0 < *(int *)(in_ECX + 0x980)) {
            do {
              if (*(int *)(local_3c + iVar6 * 4 + -4) == 0) {
                *(int *)(local_3c + iVar6 * 4 + -4) =
                     *(int *)(local_3c + iVar6 * 4 + -4) +
                     *(int *)(&DAT_007e9458 + (int)ppcVar3[1] * 4);
                local_a8 = local_a8 + 1;
                local_a4 = iVar6;
                if ((iVar6 != -1) && (bVar4 = false, local_a8 < 0xb)) goto LAB_00747db1;
                break;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < *(int *)(in_ECX + 0x980));
          }
          bVar4 = true;
LAB_00747db1:
          if (local_a4 == -1) goto LAB_00747db7;
        }
        iVar6 = *(int *)(&DAT_007e9458 + (int)ppcVar3[1] * 4);
        FUN_007486b0("\t#define ");
        FUN_007486b0(ppcVar3[3]);
        FUN_007486b0(" vout.");
        pcVar8 = local_80[local_a4];
        FUN_007486b0(pcVar8);
        uVar5 = FUN_00746950(*(int *)(local_3c + local_a4 * 4 + -4) - iVar6,iVar6);
        FUN_007486b0(uVar5);
        FUN_007486b0(&DAT_0076aa4c);
        FUN_00747320(local_94[3],pcVar8,0);
      }
      local_a0 = local_a0 + 1;
      local_98 = local_98 + 1;
    } while (local_98 < *(int *)(in_ECX + 0x89c));
  }
  local_90 = "float1";
  local_8c = "float2";
  local_88 = "float3";
  local_84 = "float4";
  iVar6 = 0;
  do {
    iVar7 = *(int *)(local_3c + iVar6 * 4 + -4);
    if (0 < iVar7) {
      FUN_007486b0(&DAT_00775790);
      FUN_007486b0((&local_94)[iVar7]);
      FUN_007486b0(" texcoord");
      FUN_007486e0(iVar6);
      FUN_007486b0(": TEXCOORD");
      FUN_007486e0(iVar6);
      FUN_007486b0(*(undefined4 *)(in_ECX + 0x988));
      FUN_007486b0(&DAT_007e9630);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  FUN_007486b0(&DAT_007e9650);
  return;
}

