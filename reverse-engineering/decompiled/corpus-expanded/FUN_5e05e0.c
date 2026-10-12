/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e05e0; label: FUN_005e05e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e05e0(byte *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_204;
  local_104[0] = '\0';
  if (param_5 != 0) {
    if (param_1[1] == 0) {
      pcVar3 = "<font color = \"#00a000\">";
    }
    else {
      pcVar3 = "<font color = \"#0000a0\">";
    }
    _sprintf(local_104,pcVar3);
  }
  _sprintf(local_204,"%d: ",param_2);
  FUN_004f1e80(local_104,local_204);
  switch(*param_1) {
  case 0x80:
    pcVar3 = "MTL              ";
    break;
  case 0x81:
    pcVar3 = "TXTRLOAD         ";
    break;
  case 0x82:
    pcVar3 = "GEOMCALL         ";
    break;
  case 0x83:
    pcVar3 = "MTXLOAD          ";
    break;
  case 0x84:
    pcVar3 = "TERMINATE        ";
    break;
  case 0x85:
    pcVar3 = "MTL_CLIP         ";
    break;
  case 0x86:
    pcVar3 = "CLUT             ";
    break;
  case 0x87:
    pcVar3 = "DUMMY            ";
    break;
  case 0x88:
    pcVar3 = "DLIST            ";
    break;
  default:
    iVar2 = FUN_00603430(param_1,local_204);
    if (iVar2 == 0) goto LAB_005e0801;
    pcVar3 = "ERROR: Unknown item.";
    break;
  case 0x8b:
    pcVar3 = "DYNAMIC GEOMETRY ";
    break;
  case 0x8c:
    pcVar3 = "TRANSFORM_REF    ";
    break;
  case 0x8d:
    pcVar3 = "NEXT             ";
    break;
  case 0x8e:
    pcVar3 = "END ITEM         ";
    break;
  case 0x8f:
    pcVar3 = "FACEON           ";
    break;
  case 0x90:
    pcVar3 = "FACEON_TRANSFORM ";
    break;
  case 0x93:
    pcVar3 = "GEOMCALL2D       ";
    break;
  case 0x94:
    pcVar3 = "LIGHTS           ";
    break;
  case 0x95:
    pcVar3 = "DEBUG GEOMCALL   ";
    break;
  case 0x97:
    pcVar3 = "LINECALL2D       ";
    break;
  case 0x9a:
    pcVar3 = "CAMERA           ";
    break;
  case 0x9b:
    pcVar3 = "FX SCREEN COPY   ";
    break;
  case 0x9c:
    pcVar3 = "FX SUN FLARE     ";
    break;
  case 0x9d:
    pcVar3 = "FX SCREEN FILTER ";
    break;
  case 0x9e:
    pcVar3 = "FX SPEED BLUR    ";
    break;
  case 0x9f:
    pcVar3 = "LINEBUFFER       ";
    break;
  case 0xa0:
    pcVar3 = "GEOM CLIPPED     ";
    break;
  case 0xad:
    pcVar3 = "INST_SURF_GEOM ITEM ";
    break;
  case 0xb0:
    pcVar3 = "LIGHTMAP ITEM    ";
  }
  _sprintf(local_204,pcVar3);
LAB_005e0801:
  FUN_004f1e80(local_104,local_204);
  _sprintf(local_204,"(%x)",*(undefined4 *)(param_1 + 4));
  FUN_004f1e80(local_104,local_204);
  if (param_3 == 0) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
    iVar2 = 0;
    if (0 < param_3) {
      do {
        if (*(uint *)(param_4 + iVar2 * 4) == (uint)*param_1) {
          bVar1 = true;
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3);
    }
  }
  if ((0 < DAT_0080ba64) && (bVar1)) {
    if (param_5 == 0) {
      FUN_005c1300();
      __security_check_cookie(local_4 ^ (uint)local_204);
      return;
    }
    FUN_005d7230(local_104);
    FUN_005d7230("</br>\n");
    if (param_1[1] == 0) {
      FUN_005d7230("<font color = \"#000000\">");
    }
  }
  if (param_5 != 0) {
    FUN_00603910(param_1,param_5);
  }
  __security_check_cookie(local_4 ^ (uint)local_204);
  return;
}

