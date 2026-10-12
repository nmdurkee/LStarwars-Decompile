/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x7275a4; label: FUN_007275a4
 */

wchar_t * FUN_007275a4(int param_1)

{
  if (param_1 < -0x7ff6cefd) {
    if (param_1 == -0x7ff6cefe) {
      return L"CRYPT_E_ASN1_EOD";
    }
    if (param_1 < -0x7ff8f949) {
      if (param_1 == -0x7ff8f94a) {
LAB_0072f71d:
        return L"RPC_S_NO_BINDINGS";
      }
      if (param_1 < -0x7ffb2ff6) {
        if (param_1 == -0x7ffb2ff7) {
          return L"XACT_E_NOASYNC";
        }
        if (param_1 < -0x7ffbfe06) {
          if (param_1 == -0x7ffbfe07) {
            return L"CO_E_ERRORINDLL";
          }
          if (param_1 < -0x7ffd735e) {
            if (param_1 == -0x7ffd735f) {
              return L"TYPE_E_OUTOFBOUNDS";
            }
            if (param_1 < -0x7ffefeed) {
              if (param_1 == -0x7ffefeee) {
                return L"RPC_E_INVALID_EXTENSION";
              }
              if (param_1 < -0x7fffbfd5) {
                if (param_1 == -0x7fffbfd6) {
                  return L"CO_E_SERVER_INIT_TIMEOUT";
                }
                if (param_1 < -0x7fffbfea) {
                  if (param_1 == -0x7fffbfeb) {
                    return L"CO_E_WRONG_SERVER_IDENTITY";
                  }
                  if (param_1 < -0x7fffbff5) {
                    if (param_1 == -0x7fffbff6) {
                      return L"CO_E_INIT_RPC_CHANNEL";
                    }
                    if (param_1 < -0x7fffbffa) {
                      if (param_1 == -0x7fffbffb) {
                        return L"E_FAIL";
                      }
                      if (param_1 == -0x7ffffff6) {
                        return L"E_PENDING";
                      }
                      if (param_1 == -0x7fffbfff) {
                        return L"E_NOTIMPL";
                      }
                      if (param_1 == -0x7fffbffe) {
                        return L"E_NOINTERFACE";
                      }
                      if (param_1 == -0x7fffbffd) {
                        return L"E_POINTER";
                      }
                      if (param_1 == -0x7fffbffc) {
                        return L"E_ABORT";
                      }
                    }
                    else {
                      if (param_1 == -0x7fffbffa) {
                        return L"CO_E_INIT_TLS";
                      }
                      if (param_1 == -0x7fffbff9) {
                        return L"CO_E_INIT_SHARED_ALLOCATOR";
                      }
                      if (param_1 == -0x7fffbff8) {
                        return L"CO_E_INIT_MEMORY_ALLOCATOR";
                      }
                      if (param_1 == -0x7fffbff7) {
                        return L"CO_E_INIT_CLASS_CACHE";
                      }
                    }
                  }
                  else {
                    switch(param_1) {
                    case -0x7fffbff5:
                      return L"CO_E_INIT_TLS_SET_CHANNEL_CONTROL";
                    case -0x7fffbff4:
                      return L"CO_E_INIT_TLS_CHANNEL_CONTROL";
                    case -0x7fffbff3:
                      return L"CO_E_INIT_UNACCEPTED_USER_ALLOCATOR";
                    case -0x7fffbff2:
                      return L"CO_E_INIT_SCM_MUTEX_EXISTS";
                    case -0x7fffbff1:
                      return L"CO_E_INIT_SCM_FILE_MAPPING_EXISTS";
                    case -0x7fffbff0:
                      return L"CO_E_INIT_SCM_MAP_VIEW_OF_FILE";
                    case -0x7fffbfef:
                      return L"CO_E_INIT_SCM_EXEC_FAILURE";
                    case -0x7fffbfee:
                      return L"CO_E_INIT_ONLY_SINGLE_THREADED";
                    case -0x7fffbfed:
                      return L"CO_E_CANT_REMOTE";
                    case -0x7fffbfec:
                      return L"CO_E_BAD_SERVER_NAME";
                    }
                  }
                }
                else {
                  switch(param_1) {
                  case -0x7fffbfea:
                    return L"CO_E_OLE1DDE_DISABLED";
                  case -0x7fffbfe9:
                    return L"CO_E_RUNAS_SYNTAX";
                  case -0x7fffbfe8:
                    return L"CO_E_CREATEPROCESS_FAILURE";
                  case -0x7fffbfe7:
                    return L"CO_E_RUNAS_CREATEPROCESS_FAILURE";
                  case -0x7fffbfe6:
                    return L"CO_E_RUNAS_LOGON_FAILURE";
                  case -0x7fffbfe5:
                    return L"CO_E_LAUNCH_PERMSSION_DENIED";
                  case -0x7fffbfe4:
                    return L"CO_E_START_SERVICE_FAILURE";
                  case -0x7fffbfe3:
                    return L"CO_E_REMOTE_COMMUNICATION_FAILURE";
                  case -0x7fffbfe2:
                    return L"CO_E_SERVER_START_TIMEOUT";
                  case -0x7fffbfe1:
                    return L"CO_E_CLSREG_INCONSISTENT";
                  case -0x7fffbfe0:
                    return L"CO_E_IIDREG_INCONSISTENT";
                  case -0x7fffbfdf:
                    return L"CO_E_NOT_SUPPORTED";
                  case -0x7fffbfde:
                    return L"CO_E_RELOAD_DLL";
                  case -0x7fffbfdd:
                    return L"CO_E_MSI_ERROR";
                  case -0x7fffbfdc:
                    return L"CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT";
                  case -0x7fffbfdb:
                    return L"CO_E_SERVER_PAUSED";
                  case -0x7fffbfda:
                    return L"CO_E_SERVER_NOT_PAUSED";
                  case -0x7fffbfd9:
                    return L"CO_E_CLASS_DISABLED";
                  case -0x7fffbfd8:
                    return L"CO_E_CLRNOTAVAILABLE";
                  case -0x7fffbfd7:
                    return L"CO_E_ASYNC_WORK_REJECTED";
                  }
                }
              }
              else if (param_1 < -0x7ffeffef) {
                if (param_1 == -0x7ffefff0) {
                  return L"RPC_E_INVALID_PARAMETER";
                }
                if (param_1 < -0x7ffefffa) {
                  if (param_1 == -0x7ffefffb) {
                    return L"RPC_E_CANTCALLOUT_INEXTERNALCALL";
                  }
                  if (param_1 < -0x7fff0000) {
                    if (param_1 == -0x7fff0001) {
                      return L"E_UNEXPECTED";
                    }
                    if (param_1 == -0x7fffbfd5) {
                      return L"CO_E_NO_SECCTX_IN_ACTIVATE";
                    }
                    if (param_1 == -0x7fffbfd0) {
                      return L"CO_E_TRACKER_CONFIG";
                    }
                    if (param_1 == -0x7fffbfcf) {
                      return L"CO_E_THREADPOOL_CONFIG";
                    }
                    if (param_1 == -0x7fffbfce) {
                      return L"CO_E_SXS_CONFIG";
                    }
                    if (param_1 == -0x7fffbfcd) {
                      return L"CO_E_MALFORMED_SPN";
                    }
                  }
                  else {
                    if (param_1 == -0x7ffeffff) {
                      return L"RPC_E_CALL_REJECTED";
                    }
                    if (param_1 == -0x7ffefffe) {
                      return L"RPC_E_CALL_CANCELED";
                    }
                    if (param_1 == -0x7ffefffd) {
                      return L"RPC_E_CANTPOST_INSENDCALL";
                    }
                    if (param_1 == -0x7ffefffc) {
                      return L"RPC_E_CANTCALLOUT_INASYNCCALL";
                    }
                  }
                }
                else {
                  switch(param_1) {
                  case -0x7ffefffa:
                    return L"RPC_E_CONNECTION_TERMINATED";
                  case -0x7ffefff9:
                    return L"RPC_E_SERVER_DIED";
                  case -0x7ffefff8:
                    return L"RPC_E_CLIENT_DIED";
                  case -0x7ffefff7:
                    return L"RPC_E_INVALID_DATAPACKET";
                  case -0x7ffefff6:
                    return L"RPC_E_CANTTRANSMIT_CALL";
                  case -0x7ffefff5:
                    return L"RPC_E_CLIENT_CANTMARSHAL_DATA";
                  case -0x7ffefff4:
                    return L"RPC_E_CLIENT_CANTUNMARSHAL_DATA";
                  case -0x7ffefff3:
                    return L"RPC_E_SERVER_CANTMARSHAL_DATA";
                  case -0x7ffefff2:
                    return L"RPC_E_SERVER_CANTUNMARSHAL_DATA";
                  case -0x7ffefff1:
                    return L"RPC_E_INVALID_DATA";
                  }
                }
              }
              else if (param_1 < -0x7ffefef7) {
                if (param_1 == -0x7ffefef8) {
                  return L"RPC_E_DISCONNECTED";
                }
                if (param_1 < -0x7ffefefc) {
                  if (param_1 == -0x7ffefefd) {
                    return L"RPC_E_NOT_REGISTERED";
                  }
                  if (param_1 == -0x7ffeffef) {
                    return L"RPC_E_CANTCALLOUT_AGAIN";
                  }
                  if (param_1 == -0x7ffeffee) {
                    return L"RPC_E_SERVER_DIED_DNE";
                  }
                  if (param_1 == -0x7ffeff00) {
                    return L"RPC_E_SYS_CALL_FAILED";
                  }
                  if (param_1 == -0x7ffefeff) {
                    return L"RPC_E_OUT_OF_RESOURCES";
                  }
                  if (param_1 == -0x7ffefefe) {
                    return L"RPC_E_ATTEMPTED_MULTITHREAD";
                  }
                }
                else {
                  if (param_1 == -0x7ffefefc) {
                    return L"RPC_E_FAULT";
                  }
                  if (param_1 == -0x7ffefefb) {
                    return L"RPC_E_SERVERFAULT";
                  }
                  if (param_1 == -0x7ffefefa) {
                    return L"RPC_E_CHANGED_MODE";
                  }
                  if (param_1 == -0x7ffefef9) {
                    return L"RPC_E_INVALIDMETHOD";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ffefef7:
                  return L"RPC_E_RETRY";
                case -0x7ffefef6:
                  return L"RPC_E_SERVERCALL_RETRYLATER";
                case -0x7ffefef5:
                  return L"RPC_E_SERVERCALL_REJECTED";
                case -0x7ffefef4:
                  return L"RPC_E_INVALID_CALLDATA";
                case -0x7ffefef3:
                  return L"RPC_E_CANTCALLOUT_ININPUTSYNCCALL";
                case -0x7ffefef2:
                  return L"RPC_E_WRONG_THREAD";
                case -0x7ffefef1:
                  return L"RPC_E_THREAD_NOT_INIT";
                case -0x7ffefef0:
                  return L"RPC_E_VERSION_MISMATCH";
                case -0x7ffefeef:
                  return L"RPC_E_INVALID_HEADER";
                }
              }
            }
            else if (param_1 < -0x7ffe0000) {
              if (param_1 == -0x7ffe0001) {
                return L"RPC_E_UNEXPECTED";
              }
              switch(param_1) {
              case -0x7ffefeed:
                return L"RPC_E_INVALID_IPID";
              case -0x7ffefeec:
                return L"RPC_E_INVALID_OBJECT";
              case -0x7ffefeeb:
                return L"RPC_S_CALLPENDING";
              case -0x7ffefeea:
                return L"RPC_S_WAITONTIMER";
              case -0x7ffefee9:
                return L"RPC_E_CALL_COMPLETE";
              case -0x7ffefee8:
                return L"RPC_E_UNSECURE_CALL";
              case -0x7ffefee7:
                return L"RPC_E_TOO_LATE";
              case -0x7ffefee6:
                return L"RPC_E_NO_GOOD_SECURITY_PACKAGES";
              case -0x7ffefee5:
                return L"RPC_E_ACCESS_DENIED";
              case -0x7ffefee4:
                return L"RPC_E_REMOTE_DISABLED";
              case -0x7ffefee3:
                return L"RPC_E_INVALID_OBJREF";
              case -0x7ffefee2:
                return L"RPC_E_NO_CONTEXT";
              case -0x7ffefee1:
                return L"RPC_E_TIMEOUT";
              case -0x7ffefee0:
                return L"RPC_E_NO_SYNC";
              case -0x7ffefedf:
                return L"RPC_E_FULLSIC_REQUIRED";
              case -0x7ffefede:
                return L"RPC_E_INVALID_STD_NAME";
              case -0x7ffefedd:
                return L"CO_E_FAILEDTOIMPERSONATE";
              case -0x7ffefedc:
                return L"CO_E_FAILEDTOGETSECCTX";
              case -0x7ffefedb:
                return L"CO_E_FAILEDTOOPENTHREADTOKEN";
              case -0x7ffefeda:
                return L"CO_E_FAILEDTOGETTOKENINFO";
              case -0x7ffefed9:
                return L"CO_E_TRUSTEEDOESNTMATCHCLIENT";
              case -0x7ffefed8:
                return L"CO_E_FAILEDTOQUERYCLIENTBLANKET";
              case -0x7ffefed7:
                return L"CO_E_FAILEDTOSETDACL";
              case -0x7ffefed6:
                return L"CO_E_ACCESSCHECKFAILED";
              case -0x7ffefed5:
                return L"CO_E_NETACCESSAPIFAILED";
              case -0x7ffefed4:
                return L"CO_E_WRONGTRUSTEENAMESYNTAX";
              case -0x7ffefed3:
                return L"CO_E_INVALIDSID";
              case -0x7ffefed2:
                return L"CO_E_CONVERSIONFAILED";
              case -0x7ffefed1:
                return L"CO_E_NOMATCHINGSIDFOUND";
              case -0x7ffefed0:
                return L"CO_E_LOOKUPACCSIDFAILED";
              case -0x7ffefecf:
                return L"CO_E_NOMATCHINGNAMEFOUND";
              case -0x7ffefece:
                return L"CO_E_LOOKUPACCNAMEFAILED";
              case -0x7ffefecd:
                return L"CO_E_SETSERLHNDLFAILED";
              case -0x7ffefecc:
                return L"CO_E_FAILEDTOGETWINDIR";
              case -0x7ffefecb:
                return L"CO_E_PATHTOOLONG";
              case -0x7ffefeca:
                return L"CO_E_FAILEDTOGENUUID";
              case -0x7ffefec9:
                return L"CO_E_FAILEDTOCREATEFILE";
              case -0x7ffefec8:
                return L"CO_E_FAILEDTOCLOSEHANDLE";
              case -0x7ffefec7:
                return L"CO_E_EXCEEDSYSACLLIMIT";
              case -0x7ffefec6:
                return L"CO_E_ACESINWRONGORDER";
              case -0x7ffefec5:
                return L"CO_E_INCOMPATIBLESTREAMVERSION";
              case -0x7ffefec4:
                return L"CO_E_FAILEDTOOPENPROCESSTOKEN";
              case -0x7ffefec3:
                return L"CO_E_DECODEFAILED";
              case -0x7ffefec1:
                return L"CO_E_ACNOTINITIALIZED";
              case -0x7ffefec0:
                return L"CO_E_CANCEL_DISABLED";
              }
            }
            else if (param_1 < -0x7ffd7fe9) {
              if (param_1 == -0x7ffd7fea) {
                return L"TYPE_E_BUFFERTOOSMALL";
              }
              switch(param_1) {
              case -0x7ffdffff:
                return L"DISP_E_UNKNOWNINTERFACE";
              case -0x7ffdfffd:
                return L"DISP_E_MEMBERNOTFOUND";
              case -0x7ffdfffc:
                return L"DISP_E_PARAMNOTFOUND";
              case -0x7ffdfffb:
                return L"DISP_E_TYPEMISMATCH";
              case -0x7ffdfffa:
                return L"DISP_E_UNKNOWNNAME";
              case -0x7ffdfff9:
                return L"DISP_E_NONAMEDARGS";
              case -0x7ffdfff8:
                return L"DISP_E_BADVARTYPE";
              case -0x7ffdfff7:
                return L"DISP_E_EXCEPTION";
              case -0x7ffdfff6:
                return L"DISP_E_OVERFLOW";
              case -0x7ffdfff5:
                return L"DISP_E_BADINDEX";
              case -0x7ffdfff4:
                return L"DISP_E_UNKNOWNLCID";
              case -0x7ffdfff3:
                return L"DISP_E_ARRAYISLOCKED";
              case -0x7ffdfff2:
                return L"DISP_E_BADPARAMCOUNT";
              case -0x7ffdfff1:
                return L"DISP_E_PARAMNOTOPTIONAL";
              case -0x7ffdfff0:
                return L"DISP_E_BADCALLEE";
              case -0x7ffdffef:
                return L"DISP_E_NOTACOLLECTION";
              case -0x7ffdffee:
                return L"DISP_E_DIVBYZERO";
              case -0x7ffdffed:
                return L"DISP_E_BUFFERTOOSMALL";
              }
            }
            else if (param_1 < -0x7ffd7fd4) {
              if (param_1 == -0x7ffd7fd5) {
                return L"TYPE_E_ELEMENTNOTFOUND";
              }
              switch(param_1) {
              case -0x7ffd7fe9:
                return L"TYPE_E_FIELDNOTFOUND";
              case -0x7ffd7fe8:
                return L"TYPE_E_INVDATAREAD";
              case -0x7ffd7fe7:
                return L"TYPE_E_UNSUPFORMAT";
              case -0x7ffd7fe4:
                return L"TYPE_E_REGISTRYACCESS";
              case -0x7ffd7fe3:
                return L"TYPE_E_LIBNOTREGISTERED";
              case -0x7ffd7fd9:
                return L"TYPE_E_UNDEFINEDTYPE";
              case -0x7ffd7fd8:
                return L"TYPE_E_QUALIFIEDNAMEDISALLOWED";
              case -0x7ffd7fd7:
                return L"TYPE_E_INVALIDSTATE";
              case -0x7ffd7fd6:
                return L"TYPE_E_WRONGTYPEKIND";
              }
            }
            else if (param_1 < -0x7ffd7742) {
              if (param_1 == -0x7ffd7743) {
                return L"TYPE_E_BADMODULEKIND";
              }
              if (param_1 == -0x7ffd7fd4) {
                return L"TYPE_E_AMBIGUOUSNAME";
              }
              if (param_1 == -0x7ffd7fd3) {
                return L"TYPE_E_NAMECONFLICT";
              }
              if (param_1 == -0x7ffd7fd2) {
                return L"TYPE_E_UNKNOWNLCID";
              }
              if (param_1 == -0x7ffd7fd1) {
                return L"TYPE_E_DLLFUNCTIONNOTFOUND";
              }
            }
            else {
              if (param_1 == -0x7ffd773b) {
                return L"TYPE_E_SIZETOOBIG";
              }
              if (param_1 == -0x7ffd773a) {
                return L"TYPE_E_DUPLICATEID";
              }
              if (param_1 == -0x7ffd7731) {
                return L"TYPE_E_INVALIDID";
              }
              if (param_1 == -0x7ffd7360) {
                return L"TYPE_E_TYPEMISMATCH";
              }
            }
          }
          else if (param_1 < -0x7ffbfefd) {
            if (param_1 == -0x7ffbfefe) {
              return L"DRAGDROP_E_INVALIDHWND";
            }
            if (param_1 < -0x7ffcfeed) {
              if (param_1 == -0x7ffcfeee) {
                return L"STG_E_NOTSIMPLEFORMAT";
              }
              if (param_1 < -0x7ffcffa8) {
                if (param_1 == -0x7ffcffa9) {
                  return L"STG_E_INVALIDPARAMETER";
                }
                if (param_1 < -0x7ffcfff9) {
                  if (param_1 == -0x7ffcfffa) {
                    return L"STG_E_INVALIDHANDLE";
                  }
                  if (param_1 < -0x7ffcfffe) {
                    if (param_1 == -0x7ffcffff) {
                      return L"STG_E_INVALIDFUNCTION";
                    }
                    if (param_1 == -0x7ffd735e) {
                      return L"TYPE_E_IOERROR";
                    }
                    if (param_1 == -0x7ffd735d) {
                      return L"TYPE_E_CANTCREATETMPFILE";
                    }
                    if (param_1 == -0x7ffd63b6) {
                      return L"TYPE_E_CANTLOADLIBRARY";
                    }
                    if (param_1 == -0x7ffd637d) {
                      return L"TYPE_E_INCONSISTENTPROPFUNCS";
                    }
                    if (param_1 == -0x7ffd637c) {
                      return L"TYPE_E_CIRCULARTYPE";
                    }
                  }
                  else {
                    if (param_1 == -0x7ffcfffe) {
                      return L"STG_E_FILENOTFOUND";
                    }
                    if (param_1 == -0x7ffcfffd) {
                      return L"STG_E_PATHNOTFOUND";
                    }
                    if (param_1 == -0x7ffcfffc) {
                      return L"STG_E_TOOMANYOPENFILES";
                    }
                    if (param_1 == -0x7ffcfffb) {
                      return L"STG_E_ACCESSDENIED";
                    }
                  }
                }
                else if (param_1 < -0x7ffcffe2) {
                  if (param_1 == -0x7ffcffe3) {
                    return L"STG_E_WRITEFAULT";
                  }
                  if (param_1 == -0x7ffcfff8) {
                    return L"STG_E_INSUFFICIENTMEMORY";
                  }
                  if (param_1 == -0x7ffcfff7) {
                    return L"STG_E_INVALIDPOINTER";
                  }
                  if (param_1 == -0x7ffcffee) {
                    return L"STG_E_NOMOREFILES";
                  }
                  if (param_1 == -0x7ffcffed) {
                    return L"STG_E_DISKISWRITEPROTECTED";
                  }
                  if (param_1 == -0x7ffcffe7) {
                    return L"STG_E_SEEKERROR";
                  }
                }
                else {
                  if (param_1 == -0x7ffcffe2) {
                    return L"STG_E_READFAULT";
                  }
                  if (param_1 == -0x7ffcffe0) {
                    return L"STG_E_SHAREVIOLATION";
                  }
                  if (param_1 == -0x7ffcffdf) {
                    return L"STG_E_LOCKVIOLATION";
                  }
                  if (param_1 == -0x7ffcffb0) {
                    return L"STG_E_FILEALREADYEXISTS";
                  }
                }
              }
              else if (param_1 < -0x7ffcfefd) {
                if (param_1 == -0x7ffcfefe) {
                  return L"STG_E_REVERTED";
                }
                if (param_1 < -0x7ffcff02) {
                  if (param_1 == -0x7ffcff03) {
                    return L"STG_E_UNKNOWN";
                  }
                  if (param_1 == -0x7ffcff90) {
                    return L"STG_E_MEDIUMFULL";
                  }
                  if (param_1 == -0x7ffcff10) {
                    return L"STG_E_PROPSETMISMATCHED";
                  }
                  if (param_1 == -0x7ffcff06) {
                    return L"STG_E_ABNORMALAPIEXIT";
                  }
                  if (param_1 == -0x7ffcff05) {
                    return L"STG_E_INVALIDHEADER";
                  }
                  if (param_1 == -0x7ffcff04) {
                    return L"STG_E_INVALIDNAME";
                  }
                }
                else {
                  if (param_1 == -0x7ffcff02) {
                    return L"STG_E_UNIMPLEMENTEDFUNCTION";
                  }
                  if (param_1 == -0x7ffcff01) {
                    return L"STG_E_INVALIDFLAG";
                  }
                  if (param_1 == -0x7ffcff00) {
                    return L"STG_E_INUSE";
                  }
                  if (param_1 == -0x7ffcfeff) {
                    return L"STG_E_NOTCURRENT";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ffcfefd:
                  return L"STG_E_CANTSAVE";
                case -0x7ffcfefc:
                  return L"STG_E_OLDFORMAT";
                case -0x7ffcfefb:
                  return L"STG_E_OLDDLL";
                case -0x7ffcfefa:
                  return L"STG_E_SHAREREQUIRED";
                case -0x7ffcfef9:
                  return L"STG_E_NOTFILEBASEDSTORAGE";
                case -0x7ffcfef8:
                  return L"STG_E_EXTANTMARSHALLINGS";
                case -0x7ffcfef7:
                  return L"STG_E_DOCFILECORRUPT";
                case -0x7ffcfef0:
                  return L"STG_E_BADBASEADDRESS";
                case -0x7ffcfeef:
                  return L"STG_E_DOCFILETOOLARGE";
                }
              }
            }
            else if (param_1 < -0x7ffbfff4) {
              if (param_1 == -0x7ffbfff5) {
                return L"OLE_E_STATIC";
              }
              if (param_1 < -0x7ffbfffe) {
                if (param_1 == -0x7ffbffff) {
                  return L"OLE_E_ADVF";
                }
                if (param_1 < -0x7ffcfcf7) {
                  if (param_1 == -0x7ffcfcf8) {
                    return L"STG_E_CSS_KEY_NOT_ESTABLISHED";
                  }
                  if (param_1 == -0x7ffcfdff) {
                    return L"STG_E_INCOMPLETE";
                  }
                  if (param_1 == -0x7ffcfdfe) {
                    return L"STG_E_TERMINATED";
                  }
                  if (param_1 == -0x7ffcfcfb) {
                    return L"STG_E_STATUS_COPY_PROTECTION_FAILURE";
                  }
                  if (param_1 == -0x7ffcfcfa) {
                    return L"STG_E_CSS_AUTHENTICATION_FAILURE";
                  }
                  if (param_1 == -0x7ffcfcf9) {
                    return L"STG_E_CSS_KEY_NOT_PRESENT";
                  }
                }
                else {
                  if (param_1 == -0x7ffcfcf7) {
                    return L"STG_E_CSS_SCRAMBLED_SECTOR";
                  }
                  if (param_1 == -0x7ffcfcf6) {
                    return L"STG_E_CSS_REGION_MISMATCH";
                  }
                  if (param_1 == -0x7ffcfcf5) {
                    return L"STG_E_RESETS_EXHAUSTED";
                  }
                  if (param_1 == -0x7ffc0000) {
                    return L"OLE_E_FIRST";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ffbfffe:
                  return L"OLE_E_ENUM_NOMORE";
                case -0x7ffbfffd:
                  return L"OLE_E_ADVISENOTSUPPORTED";
                case -0x7ffbfffc:
                  return L"OLE_E_NOCONNECTION";
                case -0x7ffbfffb:
                  return L"OLE_E_NOTRUNNING";
                case -0x7ffbfffa:
                  return L"OLE_E_NOCACHE";
                case -0x7ffbfff9:
                  return L"OLE_E_BLANK";
                case -0x7ffbfff8:
                  return L"OLE_E_CLASSDIFF";
                case -0x7ffbfff7:
                  return L"OLE_E_CANT_GETMONIKER";
                case -0x7ffbfff6:
                  return L"OLE_E_CANT_BINDTOSOURCE";
                }
              }
            }
            else if (param_1 < -0x7ffbff98) {
              if (param_1 == -0x7ffbff99) {
                return L"DV_E_STATDATA";
              }
              if (param_1 < -0x7ffbffee) {
                if (param_1 == -0x7ffbffef) {
                  return L"OLE_E_CANTCONVERT";
                }
                if (param_1 == -0x7ffbfff4) {
                  return L"OLE_E_PROMPTSAVECANCELLED";
                }
                if (param_1 == -0x7ffbfff3) {
                  return L"OLE_E_INVALIDRECT";
                }
                if (param_1 == -0x7ffbfff2) {
                  return L"OLE_E_WRONGCOMPOBJ";
                }
                if (param_1 == -0x7ffbfff1) {
                  return L"OLE_E_INVALIDHWND";
                }
                if (param_1 == -0x7ffbfff0) {
                  return L"OLE_E_NOT_INPLACEACTIVE";
                }
              }
              else {
                if (param_1 == -0x7ffbffee) {
                  return L"OLE_E_NOSTORAGE";
                }
                if (param_1 == -0x7ffbff9c) {
                  return L"DV_E_FORMATETC";
                }
                if (param_1 == -0x7ffbff9b) {
                  return L"DV_E_DVTARGETDEVICE";
                }
                if (param_1 == -0x7ffbff9a) {
                  return L"DV_E_STGMEDIUM";
                }
              }
            }
            else if (param_1 < -0x7ffbff93) {
              if (param_1 == -0x7ffbff94) {
                return L"DV_E_DVTARGETDEVICE_SIZE";
              }
              if (param_1 == -0x7ffbff98) {
                return L"DV_E_LINDEX";
              }
              if (param_1 == -0x7ffbff97) {
                return L"DV_E_TYMED";
              }
              if (param_1 == -0x7ffbff96) {
                return L"DV_E_CLIPFORMAT";
              }
              if (param_1 == -0x7ffbff95) {
                return L"DV_E_DVASPECT";
              }
            }
            else {
              if (param_1 == -0x7ffbff93) {
                return L"DV_E_NOIVIEWOBJECT";
              }
              if (param_1 == -0x7ffbff01) {
                return L"OLE_E_LAST";
              }
              if (param_1 == -0x7ffbff00) {
                return L"DRAGDROP_E_FIRST";
              }
              if (param_1 == -0x7ffbfeff) {
                return L"DRAGDROP_E_ALREADYREGISTERED";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ffbfef1:
              return L"DRAGDROP_E_LAST";
            case -0x7ffbfef0:
              return L"CLASSFACTORY_E_FIRST";
            case -0x7ffbfeef:
              return L"CLASS_E_CLASSNOTAVAILABLE";
            case -0x7ffbfeee:
              return L"CLASS_E_NOTLICENSED";
            case -0x7ffbfee1:
              return L"CLASSFACTORY_E_LAST";
            case -0x7ffbfee0:
              return L"MARSHAL_E_FIRST";
            case -0x7ffbfed1:
              return L"MARSHAL_E_LAST";
            case -0x7ffbfed0:
              return L"DATA_E_FIRST";
            case -0x7ffbfec1:
              return L"DATA_E_LAST";
            case -0x7ffbfec0:
              return L"VIEW_E_FIRST";
            case -0x7ffbfeb1:
              return L"VIEW_E_LAST";
            case -0x7ffbfeb0:
              return L"REGDB_E_FIRST";
            case -0x7ffbfeaf:
              return L"REGDB_E_WRITEREGDB";
            case -0x7ffbfeae:
              return L"REGDB_E_KEYMISSING";
            case -0x7ffbfead:
              return L"REGDB_E_INVALIDVALUE";
            case -0x7ffbfeac:
              return L"REGDB_E_CLASSNOTREG";
            case -0x7ffbfeab:
              return L"REGDB_E_IIDNOTREG";
            case -0x7ffbfeaa:
              return L"REGDB_E_BADTHREADINGMODEL";
            case -0x7ffbfea1:
              return L"REGDB_E_LAST";
            case -0x7ffbfea0:
              return L"CAT_E_FIRST";
            case -0x7ffbfe9f:
              return L"CAT_E_LAST";
            case -0x7ffbfe9c:
              return L"CS_E_FIRST";
            case -0x7ffbfe9b:
              return L"CS_E_NOT_DELETABLE";
            case -0x7ffbfe9a:
              return L"CS_E_CLASS_NOTFOUND";
            case -0x7ffbfe99:
              return L"CS_E_INVALID_VERSION";
            case -0x7ffbfe98:
              return L"CS_E_NO_CLASSSTORE";
            case -0x7ffbfe97:
              return L"CS_E_OBJECT_NOTFOUND";
            case -0x7ffbfe96:
              return L"CS_E_OBJECT_ALREADY_EXISTS";
            case -0x7ffbfe95:
              return L"CS_E_INVALID_PATH";
            case -0x7ffbfe94:
              return L"CS_E_NETWORK_ERROR";
            case -0x7ffbfe93:
              return L"CS_E_ADMIN_LIMIT_EXCEEDED";
            case -0x7ffbfe92:
              return L"CS_E_SCHEMA_MISMATCH";
            case -0x7ffbfe91:
              return L"CS_E_LAST";
            case -0x7ffbfe90:
              return L"CACHE_E_FIRST";
            case -0x7ffbfe81:
              return L"CACHE_E_LAST";
            case -0x7ffbfe80:
              return L"OLEOBJ_E_FIRST";
            case -0x7ffbfe7f:
              return L"OLEOBJ_E_INVALIDVERB";
            case -0x7ffbfe71:
              return L"OLEOBJ_E_LAST";
            case -0x7ffbfe70:
              return L"CLIENTSITE_E_FIRST";
            case -0x7ffbfe61:
              return L"CLIENTSITE_E_LAST";
            case -0x7ffbfe60:
              return L"INPLACE_E_NOTUNDOABLE";
            case -0x7ffbfe5f:
              return L"INPLACE_E_NOTOOLSPACE";
            case -0x7ffbfe51:
              return L"INPLACE_E_LAST";
            case -0x7ffbfe50:
              return L"ENUM_E_FIRST";
            case -0x7ffbfe41:
              return L"ENUM_E_LAST";
            case -0x7ffbfe40:
              return L"CONVERT10_E_FIRST";
            case -0x7ffbfe3f:
              return L"CONVERT10_E_OLESTREAM_PUT";
            case -0x7ffbfe3e:
              return L"CONVERT10_E_OLESTREAM_FMT";
            case -0x7ffbfe3d:
              return L"CONVERT10_E_OLESTREAM_BITMAP_TO_DIB";
            case -0x7ffbfe3c:
              return L"CONVERT10_E_STG_FMT";
            case -0x7ffbfe3b:
              return L"CONVERT10_E_STG_NO_STD_STREAM";
            case -0x7ffbfe3a:
              return L"CONVERT10_E_STG_DIB_TO_BITMAP";
            case -0x7ffbfe31:
              return L"CONVERT10_E_LAST";
            case -0x7ffbfe30:
              return L"CLIPBRD_E_FIRST";
            case -0x7ffbfe2f:
              return L"CLIPBRD_E_CANT_EMPTY";
            case -0x7ffbfe2e:
              return L"CLIPBRD_E_CANT_SET";
            case -0x7ffbfe2d:
              return L"CLIPBRD_E_BAD_DATA";
            case -0x7ffbfe2c:
              return L"CLIPBRD_E_CANT_CLOSE";
            case -0x7ffbfe21:
              return L"CLIPBRD_E_LAST";
            case -0x7ffbfe20:
              return L"MK_E_FIRST";
            case -0x7ffbfe1f:
              return L"MK_E_EXCEEDEDDEADLINE";
            case -0x7ffbfe1e:
              return L"MK_E_NEEDGENERIC";
            case -0x7ffbfe1d:
              return L"MK_E_UNAVAILABLE";
            case -0x7ffbfe1c:
              return L"MK_E_SYNTAX";
            case -0x7ffbfe1b:
              return L"MK_E_NOOBJECT";
            case -0x7ffbfe1a:
              return L"MK_E_INVALIDEXTENSION";
            case -0x7ffbfe19:
              return L"MK_E_INTERMEDIATEINTERFACENOTSUPPORTED";
            case -0x7ffbfe18:
              return L"MK_E_NOTBINDABLE";
            case -0x7ffbfe17:
              return L"MK_E_NOTBOUND";
            case -0x7ffbfe16:
              return L"MK_E_CANTOPENFILE";
            case -0x7ffbfe15:
              return L"MK_E_MUSTBOTHERUSER";
            case -0x7ffbfe14:
              return L"MK_E_NOINVERSE";
            case -0x7ffbfe13:
              return L"MK_E_NOSTORAGE";
            case -0x7ffbfe12:
              return L"MK_E_NOPREFIX";
            case -0x7ffbfe11:
              return L"MK_E_LAST";
            case -0x7ffbfe10:
              return L"CO_E_NOTINITIALIZED";
            case -0x7ffbfe0f:
              return L"CO_E_ALREADYINITIALIZED";
            case -0x7ffbfe0e:
              return L"CO_E_CANTDETERMINECLASS";
            case -0x7ffbfe0d:
              return L"CO_E_CLASSSTRING";
            case -0x7ffbfe0c:
              return L"CO_E_IIDSTRING";
            case -0x7ffbfe0b:
              return L"CO_E_APPNOTFOUND";
            case -0x7ffbfe0a:
              return L"CO_E_APPSINGLEUSE";
            case -0x7ffbfe09:
              return L"CO_E_ERRORINAPP";
            case -0x7ffbfe08:
              return L"CO_E_DLLNOTFOUND";
            }
          }
        }
        else if (param_1 < -0x7ffbfc0d) {
          if (param_1 == -0x7ffbfc0e) {
            return L"VFW_E_BAD_KEY";
          }
          if (param_1 + 0x7ffbfe06U < 0x10c) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
            switch(*(undefined1 *)(param_1 + -0x7f90c778)) {
            case 0:
              return L"CO_E_WRONGOSFORAPP";
            case 1:
              return L"CO_E_OBJNOTREG";
            case 2:
              return L"CO_E_OBJISREG";
            case 3:
              return L"CO_E_OBJNOTCONNECTED";
            case 4:
              return L"CO_E_APPDIDNTREG";
            case 5:
              return L"CO_E_RELEASED";
            case 6:
              return L"DIERR_INSUFFICIENTPRIVS & VFW_E_INVALIDMEDIATYPE";
            case 7:
              return L"DIERR_DEVICEFULL & VFW_E_INVALIDSUBTYPE & DMO_E_INVALIDSTREAMINDEX";
            case 8:
              return L"DIERR_MOREDATA & VFW_E_NEED_OWNER & DMO_E_INVALIDTYPE";
            case 9:
              return L"DIERR_NOTDOWNLOADED & VFW_E_ENUM_OUT_OF_SYNC & DMO_E_TYPE_NOT_SET";
            case 10:
              return L"DIERR_HASEFFECTS & VFW_E_ALREADY_CONNECTED & DMO_E_NOTACCEPTING";
            case 0xb:
              return L"DIERR_NOTEXCLUSIVEACQUIRED & VFW_E_FILTER_ACTIVE & DMO_E_TYPE_NOT_ACCEPTED";
            case 0xc:
              return L"DIERR_INCOMPLETEEFFECT & VFW_E_NO_TYPES & DMO_E_NO_MORE_ITEMS";
            case 0xd:
              return L"DIERR_NOTBUFFERED & VFW_E_NO_ACCEPTABLE_TYPES";
            case 0xe:
              return L"DIERR_EFFECTPLAYING & VFW_E_INVALID_DIRECTION";
            case 0xf:
              return L"DIERR_UNPLUGGED & VFW_E_NOT_CONNECTED";
            case 0x10:
              return L"DIERR_REPORTFULL & VFW_E_NO_ALLOCATOR";
            case 0x11:
              return L"DIERR_MAPFILEFAIL & VFW_E_RUNTIME_ERROR";
            case 0x12:
              return L"VFW_E_BUFFER_NOTSET";
            case 0x13:
              return L"VFW_E_BUFFER_OVERFLOW";
            case 0x14:
              return L"VFW_E_BADALIGN";
            case 0x15:
              return L"VFW_E_ALREADY_COMMITTED";
            case 0x16:
              return L"VFW_E_BUFFERS_OUTSTANDING";
            case 0x17:
              return L"VFW_E_NOT_COMMITTED";
            case 0x18:
              return L"VFW_E_SIZENOTSET";
            case 0x19:
              return L"VFW_E_NO_CLOCK";
            case 0x1a:
              return L"VFW_E_NO_SINK";
            case 0x1b:
              return L"VFW_E_NO_INTERFACE";
            case 0x1c:
              return L"VFW_E_NOT_FOUND";
            case 0x1d:
              return L"VFW_E_CANNOT_CONNECT";
            case 0x1e:
              return L"VFW_E_CANNOT_RENDER";
            case 0x1f:
              return L"VFW_E_CHANGING_FORMAT";
            case 0x20:
              return L"VFW_E_NO_COLOR_KEY_SET";
            case 0x21:
              return L"VFW_E_NOT_OVERLAY_CONNECTION";
            case 0x22:
              return L"VFW_E_NOT_SAMPLE_CONNECTION";
            case 0x23:
              return L"VFW_E_PALETTE_SET";
            case 0x24:
              return L"VFW_E_COLOR_KEY_SET";
            case 0x25:
              return L"VFW_E_NO_COLOR_KEY_FOUND";
            case 0x26:
              return L"VFW_E_NO_PALETTE_AVAILABLE";
            case 0x27:
              return L"VFW_E_NO_DISPLAY_PALETTE";
            case 0x28:
              return L"VFW_E_TOO_MANY_COLORS";
            case 0x29:
              return L"VFW_E_STATE_CHANGED";
            case 0x2a:
              return L"VFW_E_NOT_STOPPED";
            case 0x2b:
              return L"VFW_E_NOT_PAUSED";
            case 0x2c:
              return L"VFW_E_NOT_RUNNING";
            case 0x2d:
              return L"VFW_E_WRONG_STATE";
            case 0x2e:
              return L"VFW_E_START_TIME_AFTER_END";
            case 0x2f:
              return L"VFW_E_INVALID_RECT";
            case 0x30:
              return L"VFW_E_TYPE_NOT_ACCEPTED";
            case 0x31:
              return L"VFW_E_SAMPLE_REJECTED";
            case 0x32:
              return L"VFW_E_SAMPLE_REJECTED_EOS";
            case 0x33:
              return L"VFW_E_DUPLICATE_NAME";
            case 0x34:
              return L"VFW_E_TIMEOUT";
            case 0x35:
              return L"VFW_E_INVALID_FILE_FORMAT";
            case 0x36:
              return L"VFW_E_ENUM_OUT_OF_RANGE";
            case 0x37:
              return L"VFW_E_CIRCULAR_GRAPH";
            case 0x38:
              return L"VFW_E_NOT_ALLOWED_TO_SAVE";
            case 0x39:
              return L"VFW_E_TIME_ALREADY_PASSED";
            case 0x3a:
              return L"VFW_E_ALREADY_CANCELLED";
            case 0x3b:
              return L"VFW_E_CORRUPT_GRAPH_FILE";
            case 0x3c:
              return L"VFW_E_ADVISE_ALREADY_SET";
            case 0x3d:
              return L"VFW_E_NO_MODEX_AVAILABLE";
            case 0x3e:
              return L"VFW_E_NO_ADVISE_SET";
            case 0x3f:
              return L"VFW_E_NO_FULLSCREEN";
            case 0x40:
              return L"VFW_E_IN_FULLSCREEN_MODE";
            case 0x41:
              return L"VFW_E_UNKNOWN_FILE_TYPE";
            case 0x42:
              return L"VFW_E_CANNOT_LOAD_SOURCE_FILTER";
            case 0x43:
              return L"VFW_E_FILE_TOO_SHORT";
            case 0x44:
              return L"VFW_E_INVALID_FILE_VERSION";
            case 0x45:
              return L"VFW_E_INVALID_CLSID";
            case 0x46:
              return L"VFW_E_INVALID_MEDIA_TYPE";
            case 0x47:
              return L"VFW_E_SAMPLE_TIME_NOT_SET";
            case 0x48:
              return L"VFW_E_MEDIA_TIME_NOT_SET";
            case 0x49:
              return L"VFW_E_NO_TIME_FORMAT_SET";
            case 0x4a:
              return L"VFW_E_MONO_AUDIO_HW";
            case 0x4b:
              return L"VFW_E_NO_DECOMPRESSOR";
            case 0x4c:
              return L"VFW_E_NO_AUDIO_HARDWARE";
            case 0x4d:
              return L"VFW_E_RPZA";
            case 0x4e:
              return L"VFW_E_PROCESSOR_NOT_SUITABLE";
            case 0x4f:
              return L"VFW_E_UNSUPPORTED_AUDIO";
            case 0x50:
              return L"VFW_E_UNSUPPORTED_VIDEO";
            case 0x51:
              return L"VFW_E_MPEG_NOT_CONSTRAINED";
            case 0x52:
              return L"VFW_E_NOT_IN_GRAPH";
            case 0x53:
              return L"VFW_E_NO_TIME_FORMAT";
            case 0x54:
              return L"VFW_E_READ_ONLY";
            case 0x55:
              return L"VFW_E_BUFFER_UNDERFLOW";
            case 0x56:
              return L"VFW_E_UNSUPPORTED_STREAM";
            case 0x57:
              return L"VFW_E_NO_TRANSPORT";
            case 0x58:
              return L"VFW_E_BAD_VIDEOCD";
            case 0x59:
              return L"VFW_E_OUT_OF_VIDEO_MEMORY";
            case 0x5a:
              return L"VFW_E_VP_NEGOTIATION_FAILED";
            case 0x5b:
              return L"VFW_E_DDRAW_CAPS_NOT_SUITABLE";
            case 0x5c:
              return L"VFW_E_NO_VP_HARDWARE";
            case 0x5d:
              return L"VFW_E_NO_CAPTURE_HARDWARE";
            case 0x5e:
              return L"VFW_E_DVD_OPERATION_INHIBITED";
            case 0x5f:
              return L"VFW_E_DVD_INVALIDDOMAIN";
            case 0x60:
              return L"VFW_E_DVD_NO_BUTTON";
            case 0x61:
              return L"VFW_E_DVD_GRAPHNOTREADY";
            case 0x62:
              return L"VFW_E_DVD_RENDERFAIL";
            case 99:
              return L"VFW_E_DVD_DECNOTENOUGH";
            case 100:
              return L"VFW_E_DDRAW_VERSION_NOT_SUITABLE";
            case 0x65:
              return L"VFW_E_COPYPROT_FAILED";
            case 0x66:
              return L"VFW_E_TIME_EXPIRED";
            case 0x67:
              return L"VFW_E_DVD_WRONG_SPEED";
            case 0x68:
              return L"VFW_E_DVD_MENU_DOES_NOT_EXIST";
            case 0x69:
              return L"VFW_E_DVD_CMD_CANCELLED";
            case 0x6a:
              return L"VFW_E_DVD_STATE_WRONG_VERSION";
            case 0x6b:
              return L"VFW_E_DVD_STATE_CORRUPT";
            case 0x6c:
              return L"VFW_E_DVD_STATE_WRONG_DISC";
            case 0x6d:
              return L"VFW_E_DVD_INCOMPATIBLE_REGION";
            case 0x6e:
              return L"VFW_E_DVD_NO_ATTRIBUTES";
            case 0x6f:
              return L"VFW_E_DVD_NO_GOUP_PGC";
            case 0x70:
              return L"VFW_E_DVD_LOW_PARENTAL_LEVEL";
            case 0x71:
              return L"VFW_E_DVD_NOT_IN_KARAOKE_MODE";
            case 0x72:
              return L"VFW_E_FRAME_STEP_UNSUPPORTED";
            case 0x73:
              return L"VFW_E_DVD_STREAM_DISABLED";
            case 0x74:
              return L"VFW_E_DVD_TITLE_UNKNOWN";
            case 0x75:
              return L"VFW_E_DVD_INVALID_DISC";
            case 0x76:
              return L"VFW_E_DVD_NO_RESUME_INFORMATION";
            case 0x77:
              return L"VFW_E_PIN_ALREADY_BLOCKED_ON_THIS_THREAD";
            case 0x78:
              return L"VFW_E_PIN_ALREADY_BLOCKED";
            case 0x79:
              return L"VFW_E_CERTIFICATION_FAILURE";
            case 0x7a:
              return L"DIERR_DRIVERFIRST";
            case 0x7b:
              return L"DIERR_DRIVERFIRST+1";
            case 0x7c:
              return L"DIERR_DRIVERFIRST+2";
            case 0x7d:
              return L"DIERR_DRIVERFIRST+3";
            case 0x7e:
              return L"DIERR_DRIVERFIRST+4";
            case 0x7f:
              return L"DIERR_DRIVERFIRST+5";
            }
          }
        }
        else if (param_1 < -0x7ffbeffe) {
          if (param_1 == -0x7ffbefff) {
            return L"WBEM_E_FAILED";
          }
          switch(param_1) {
          case -0x7ffbfc01:
            return L"DIERR_DRIVERLAST";
          case -0x7ffbfc00:
            return L"DIERR_INVALIDCLASSINSTALLER";
          case -0x7ffbfbff:
            return L"DIERR_CANCELLED & MS_E_SAMPLEALLOC";
          case -0x7ffbfbfe:
            return L"DIERR_BADINF & MS_E_PURPOSEID";
          case -0x7ffbfbfd:
            return L"MS_E_NOSTREAM";
          case -0x7ffbfbfc:
            return L"MS_E_NOSEEKING";
          case -0x7ffbfbfb:
            return L"MS_E_INCOMPATIBLE";
          case -0x7ffbfbfa:
            return L"MS_E_BUSY";
          case -0x7ffbfbf9:
            return L"MS_E_NOTINIT";
          case -0x7ffbfbf8:
            return L"MS_E_SOURCEALREADYDEFINED";
          case -0x7ffbfbf7:
            return L"MS_E_INVALIDSTREAMTYPE";
          case -0x7ffbfbf6:
            return L"MS_E_NOTRUNNING";
          }
        }
        else if (param_1 < -0x7ffbecf6) {
          if (param_1 == -0x7ffbecf7) {
            return L"SCHED_E_TRIGGER_NOT_FOUND";
          }
          switch(param_1) {
          case -0x7ffbeffe:
            return L"WBEM_E_NOT_FOUND";
          case -0x7ffbeffd:
            return L"WBEM_E_ACCESS_DENIED";
          case -0x7ffbeffc:
            return L"WBEM_E_PROVIDER_FAILURE";
          case -0x7ffbeffb:
            return L"WBEM_E_TYPE_MISMATCH";
          case -0x7ffbeffa:
            return L"WBEM_E_OUT_OF_MEMORY";
          case -0x7ffbeff9:
            return L"WBEM_E_INVALID_CONTEXT";
          case -0x7ffbeff8:
            return L"WBEM_E_INVALID_PARAMETER";
          case -0x7ffbeff7:
            return L"WBEM_E_NOT_AVAILABLE";
          case -0x7ffbeff6:
            return L"WBEM_E_CRITICAL_ERROR";
          case -0x7ffbeff5:
            return L"WBEM_E_INVALID_STREAM";
          case -0x7ffbeff4:
            return L"WBEM_E_NOT_SUPPORTED";
          case -0x7ffbeff3:
            return L"WBEM_E_INVALID_SUPERCLASS";
          case -0x7ffbeff2:
            return L"WBEM_E_INVALID_NAMESPACE";
          case -0x7ffbeff1:
            return L"WBEM_E_INVALID_OBJECT";
          case -0x7ffbeff0:
            return L"WBEM_E_INVALID_CLASS";
          case -0x7ffbefef:
            return L"WBEM_E_PROVIDER_NOT_FOUND";
          case -0x7ffbefee:
            return L"WBEM_E_INVALID_PROVIDER_REGISTRATION";
          case -0x7ffbefed:
            return L"WBEM_E_PROVIDER_LOAD_FAILURE";
          case -0x7ffbefec:
            return L"WBEM_E_INITIALIZATION_FAILURE";
          case -0x7ffbefeb:
            return L"WBEM_E_TRANSPORT_FAILURE";
          case -0x7ffbefea:
            return L"WBEM_E_INVALID_OPERATION";
          case -0x7ffbefe9:
            return L"WBEM_E_INVALID_QUERY";
          case -0x7ffbefe8:
            return L"WBEM_E_INVALID_QUERY_TYPE";
          case -0x7ffbefe7:
            return L"WBEM_E_ALREADY_EXISTS";
          case -0x7ffbefe6:
            return L"WBEM_E_OVERRIDE_NOT_ALLOWED";
          case -0x7ffbefe5:
            return L"WBEM_E_PROPAGATED_QUALIFIER";
          case -0x7ffbefe4:
            return L"WBEM_E_PROPAGATED_PROPERTY";
          case -0x7ffbefe3:
            return L"WBEM_E_UNEXPECTED";
          case -0x7ffbefe2:
            return L"WBEM_E_ILLEGAL_OPERATION";
          case -0x7ffbefe1:
            return L"WBEM_E_CANNOT_BE_KEY";
          case -0x7ffbefe0:
            return L"WBEM_E_INCOMPLETE_CLASS";
          case -0x7ffbefdf:
            return L"WBEM_E_INVALID_SYNTAX";
          case -0x7ffbefde:
            return L"WBEM_E_NONDECORATED_OBJECT";
          case -0x7ffbefdd:
            return L"WBEM_E_READ_ONLY";
          case -0x7ffbefdc:
            return L"WBEM_E_PROVIDER_NOT_CAPABLE";
          case -0x7ffbefdb:
            return L"WBEM_E_CLASS_HAS_CHILDREN";
          case -0x7ffbefda:
            return L"WBEM_E_CLASS_HAS_INSTANCES";
          case -0x7ffbefd9:
            return L"WBEM_E_QUERY_NOT_IMPLEMENTED";
          case -0x7ffbefd8:
            return L"WBEM_E_ILLEGAL_NULL";
          case -0x7ffbefd7:
            return L"WBEM_E_INVALID_QUALIFIER_TYPE";
          case -0x7ffbefd6:
            return L"WBEM_E_INVALID_PROPERTY_TYPE";
          case -0x7ffbefd5:
            return L"WBEM_E_VALUE_OUT_OF_RANGE";
          case -0x7ffbefd4:
            return L"WBEM_E_CANNOT_BE_SINGLETON";
          case -0x7ffbefd3:
            return L"WBEM_E_INVALID_CIM_TYPE";
          case -0x7ffbefd2:
            return L"WBEM_E_INVALID_METHOD";
          case -0x7ffbefd1:
            return L"WBEM_E_INVALID_METHOD_PARAMETERS";
          case -0x7ffbefd0:
            return L"WBEM_E_SYSTEM_PROPERTY";
          case -0x7ffbefcf:
            return L"WBEM_E_INVALID_PROPERTY";
          case -0x7ffbefce:
            return L"WBEM_E_CALL_CANCELLED";
          case -0x7ffbefcd:
            return L"WBEM_E_SHUTTING_DOWN";
          case -0x7ffbefcc:
            return L"WBEM_E_PROPAGATED_METHOD";
          case -0x7ffbefcb:
            return L"WBEM_E_UNSUPPORTED_PARAMETER";
          case -0x7ffbefca:
            return L"WBEM_E_MISSING_PARAMETER_ID";
          case -0x7ffbefc9:
            return L"WBEM_E_INVALID_PARAMETER_ID";
          case -0x7ffbefc8:
            return L"WBEM_E_NONCONSECUTIVE_PARAMETER_IDS";
          case -0x7ffbefc7:
            return L"WBEM_E_PARAMETER_ID_ON_RETVAL";
          case -0x7ffbefc6:
            return L"WBEM_E_INVALID_OBJECT_PATH";
          case -0x7ffbefc5:
            return L"WBEM_E_OUT_OF_DISK_SPACE";
          case -0x7ffbefc4:
            return L"WBEM_E_BUFFER_TOO_SMALL";
          case -0x7ffbefc3:
            return L"WBEM_E_UNSUPPORTED_PUT_EXTENSION";
          case -0x7ffbefc2:
            return L"WBEM_E_UNKNOWN_OBJECT_TYPE";
          case -0x7ffbefc1:
            return L"WBEM_E_UNKNOWN_PACKET_TYPE";
          case -0x7ffbefc0:
            return L"WBEM_E_MARSHAL_VERSION_MISMATCH";
          case -0x7ffbefbf:
            return L"WBEM_E_MARSHAL_INVALID_SIGNATURE";
          case -0x7ffbefbe:
            return L"WBEM_E_INVALID_QUALIFIER";
          case -0x7ffbefbd:
            return L"WBEM_E_INVALID_DUPLICATE_PARAMETER";
          case -0x7ffbefbc:
            return L"WBEM_E_TOO_MUCH_DATA";
          case -0x7ffbefbb:
            return L"WBEM_E_SERVER_TOO_BUSY";
          case -0x7ffbefba:
            return L"WBEM_E_INVALID_FLAVOR";
          case -0x7ffbefb9:
            return L"WBEM_E_CIRCULAR_REFERENCE";
          case -0x7ffbefb8:
            return L"WBEM_E_UNSUPPORTED_CLASS_UPDATE";
          case -0x7ffbefb7:
            return L"WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE";
          case -0x7ffbefb0:
            return L"WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE";
          case -0x7ffbefaf:
            return L"WBEM_E_TOO_MANY_PROPERTIES";
          case -0x7ffbefae:
            return L"WBEM_E_UPDATE_TYPE_MISMATCH";
          case -0x7ffbefad:
            return L"WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED";
          case -0x7ffbefac:
            return L"WBEM_E_UPDATE_PROPAGATED_METHOD";
          case -0x7ffbefab:
            return L"WBEM_E_METHOD_NOT_IMPLEMENTED";
          case -0x7ffbefaa:
            return L"WBEM_E_METHOD_DISABLED";
          case -0x7ffbefa9:
            return L"WBEM_E_REFRESHER_BUSY";
          case -0x7ffbefa8:
            return L"WBEM_E_UNPARSABLE_QUERY";
          case -0x7ffbefa7:
            return L"WBEM_E_NOT_EVENT_CLASS";
          case -0x7ffbefa6:
            return L"WBEM_E_MISSING_GROUP_WITHIN";
          case -0x7ffbefa5:
            return L"WBEM_E_MISSING_AGGREGATION_LIST";
          case -0x7ffbefa4:
            return L"WBEM_E_PROPERTY_NOT_AN_OBJECT";
          case -0x7ffbefa3:
            return L"WBEM_E_AGGREGATING_BY_OBJECT";
          case -0x7ffbefa1:
            return L"WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY";
          case -0x7ffbefa0:
            return L"WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING";
          case -0x7ffbef9f:
            return L"WBEM_E_QUEUE_OVERFLOW";
          case -0x7ffbef9e:
            return L"WBEM_E_PRIVILEGE_NOT_HELD";
          case -0x7ffbef9d:
            return L"WBEM_E_INVALID_OPERATOR";
          case -0x7ffbef9c:
            return L"WBEM_E_LOCAL_CREDENTIALS";
          case -0x7ffbef9b:
            return L"WBEM_E_CANNOT_BE_ABSTRACT";
          case -0x7ffbef9a:
            return L"WBEM_E_AMENDED_OBJECT";
          case -0x7ffbef99:
            return L"WBEM_E_CLIENT_TOO_SLOW";
          case -0x7ffbef98:
            return L"WBEM_E_NULL_SECURITY_DESCRIPTOR";
          case -0x7ffbef97:
            return L"WBEM_E_TIMED_OUT";
          case -0x7ffbef96:
            return L"WBEM_E_INVALID_ASSOCIATION";
          case -0x7ffbef95:
            return L"WBEM_E_AMBIGUOUS_OPERATION";
          case -0x7ffbef94:
            return L"WBEM_E_QUOTA_VIOLATION";
          case -0x7ffbef93:
            return L"WBEM_E_RESERVED_001";
          case -0x7ffbef92:
            return L"WBEM_E_RESERVED_002";
          case -0x7ffbef91:
            return L"WBEM_E_UNSUPPORTED_LOCALE";
          case -0x7ffbef90:
            return L"WBEM_E_HANDLE_OUT_OF_DATE";
          case -0x7ffbef8f:
            return L"WBEM_E_CONNECTION_FAILED";
          case -0x7ffbef8e:
            return L"WBEM_E_INVALID_HANDLE_REQUEST";
          case -0x7ffbef8d:
            return L"WBEM_E_PROPERTY_NAME_TOO_WIDE";
          case -0x7ffbef8c:
            return L"WBEM_E_CLASS_NAME_TOO_WIDE";
          case -0x7ffbef8b:
            return L"WBEM_E_METHOD_NAME_TOO_WIDE";
          case -0x7ffbef8a:
            return L"WBEM_E_QUALIFIER_NAME_TOO_WIDE";
          case -0x7ffbef89:
            return L"WBEM_E_RERUN_COMMAND";
          case -0x7ffbef88:
            return L"WBEM_E_DATABASE_VER_MISMATCH";
          case -0x7ffbef87:
            return L"WBEM_E_VETO_DELETE";
          case -0x7ffbef86:
            return L"WBEM_E_VETO_PUT";
          case -0x7ffbef80:
            return L"WBEM_E_INVALID_LOCALE";
          case -0x7ffbef7f:
            return L"WBEM_E_PROVIDER_SUSPENDED";
          case -0x7ffbef7e:
            return L"WBEM_E_SYNCHRONIZATION_REQUIRED";
          case -0x7ffbef7d:
            return L"WBEM_E_NO_SCHEMA";
          case -0x7ffbef7c:
            return L"WBEM_E_PROVIDER_ALREADY_REGISTERED";
          case -0x7ffbef7b:
            return L"WBEM_E_PROVIDER_NOT_REGISTERED";
          case -0x7ffbef7a:
            return L"WBEM_E_FATAL_TRANSPORT_ERROR";
          case -0x7ffbef79:
            return L"WBEM_E_ENCRYPTED_CONNECTION_REQUIRED";
          case -0x7ffbef78:
            return L"WBEM_E_PROVIDER_TIMED_OUT";
          case -0x7ffbef77:
            return L"WBEM_E_NO_KEY";
          case -0x7ffbef76:
            return L"WBEM_E_PROVIDER_DISABLED";
          }
        }
        else if (param_1 < -0x7ffbdffe) {
          if (param_1 == -0x7ffbdfff) {
            return L"WBEMESS_E_REGISTRATION_TOO_BROAD";
          }
          switch(param_1) {
          case -0x7ffbecf6:
            return L"SCHED_E_TASK_NOT_READY";
          case -0x7ffbecf5:
            return L"SCHED_E_TASK_NOT_RUNNING";
          case -0x7ffbecf4:
            return L"SCHED_E_SERVICE_NOT_INSTALLED";
          case -0x7ffbecf3:
            return L"SCHED_E_CANNOT_OPEN_TASK";
          case -0x7ffbecf2:
            return L"SCHED_E_INVALID_TASK";
          case -0x7ffbecf1:
            return L"SCHED_E_ACCOUNT_INFORMATION_NOT_SET";
          case -0x7ffbecf0:
            return L"SCHED_E_ACCOUNT_NAME_NOT_FOUND";
          case -0x7ffbecef:
            return L"SCHED_E_ACCOUNT_DBASE_CORRUPT";
          case -0x7ffbecee:
            return L"SCHED_E_NO_SECURITY_SERVICES";
          case -0x7ffbeced:
            return L"SCHED_E_UNKNOWN_OBJECT_VERSION";
          case -0x7ffbecec:
            return L"SCHED_E_UNSUPPORTED_ACCOUNT_OPTION";
          case -0x7ffbeceb:
            return L"SCHED_E_SERVICE_NOT_RUNNING";
          }
        }
        else if (param_1 < -0x7ffbbfe2) {
          if (param_1 == -0x7ffbbfe3) {
            return L"WBEMMOF_E_OUT_OF_RANGE";
          }
          if (param_1 < -0x7ffbbff1) {
            if (param_1 == -0x7ffbbff2) {
              return L"WBEMMOF_E_UNEXPECTED_ALIAS";
            }
            if (param_1 < -0x7ffbbff8) {
              if (param_1 == -0x7ffbbff9) {
                return L"WBEMMOF_E_ILLEGAL_CONSTANT_VALUE";
              }
              if (param_1 == -0x7ffbdffe) {
                return L"WBEMESS_E_REGISTRATION_TOO_PRECISE";
              }
              if (param_1 == -0x7ffbbfff) {
                return L"WBEMMOF_E_EXPECTED_QUALIFIER_NAME";
              }
              if (param_1 == -0x7ffbbffe) {
                return L"WBEMMOF_E_EXPECTED_SEMI";
              }
              if (param_1 == -0x7ffbbffd) {
                return L"WBEMMOF_E_EXPECTED_OPEN_BRACE";
              }
              if (param_1 == -0x7ffbbffc) {
                return L"WBEMMOF_E_EXPECTED_CLOSE_BRACE";
              }
              if (param_1 == -0x7ffbbffb) {
                return L"WBEMMOF_E_EXPECTED_CLOSE_BRACKET";
              }
              if (param_1 == -0x7ffbbffa) {
                return L"WBEMMOF_E_EXPECTED_CLOSE_PAREN";
              }
            }
            else {
              if (param_1 == -0x7ffbbff8) {
                return L"WBEMMOF_E_EXPECTED_TYPE_IDENTIFIER";
              }
              if (param_1 == -0x7ffbbff7) {
                return L"WBEMMOF_E_EXPECTED_OPEN_PAREN";
              }
              if (param_1 == -0x7ffbbff6) {
                return L"WBEMMOF_E_UNRECOGNIZED_TOKEN";
              }
              if (param_1 == -0x7ffbbff5) {
                return L"WBEMMOF_E_UNRECOGNIZED_TYPE";
              }
              if (param_1 == -0x7ffbbff4) {
                return L"WBEMMOF_E_EXPECTED_PROPERTY_NAME";
              }
              if (param_1 == -0x7ffbbff3) {
                return L"WBEMMOF_E_TYPEDEF_NOT_SUPPORTED";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ffbbff1:
              return L"WBEMMOF_E_UNEXPECTED_ARRAY_INIT";
            case -0x7ffbbff0:
              return L"WBEMMOF_E_INVALID_AMENDMENT_SYNTAX";
            case -0x7ffbbfef:
              return L"WBEMMOF_E_INVALID_DUPLICATE_AMENDMENT";
            case -0x7ffbbfee:
              return L"WBEMMOF_E_INVALID_PRAGMA";
            case -0x7ffbbfed:
              return L"WBEMMOF_E_INVALID_NAMESPACE_SYNTAX";
            case -0x7ffbbfec:
              return L"WBEMMOF_E_EXPECTED_CLASS_NAME";
            case -0x7ffbbfeb:
              return L"WBEMMOF_E_TYPE_MISMATCH";
            case -0x7ffbbfea:
              return L"WBEMMOF_E_EXPECTED_ALIAS_NAME";
            case -0x7ffbbfe9:
              return L"WBEMMOF_E_INVALID_CLASS_DECLARATION";
            case -0x7ffbbfe8:
              return L"WBEMMOF_E_INVALID_INSTANCE_DECLARATION";
            case -0x7ffbbfe7:
              return L"WBEMMOF_E_EXPECTED_DOLLAR";
            case -0x7ffbbfe6:
              return L"WBEMMOF_E_CIMTYPE_QUALIFIER";
            case -0x7ffbbfe5:
              return L"WBEMMOF_E_DUPLICATE_PROPERTY";
            case -0x7ffbbfe4:
              return L"WBEMMOF_E_INVALID_NAMESPACE_SPECIFICATION";
            }
          }
        }
        else if (param_1 < -0x7ffb2fff) {
          if (param_1 == -0x7ffb3000) {
            return L"XACT_E_FIRST";
          }
          switch(param_1) {
          case -0x7ffbbfe2:
            return L"WBEMMOF_E_INVALID_FILE";
          case -0x7ffbbfe1:
            return L"WBEMMOF_E_ALIASES_IN_EMBEDDED";
          case -0x7ffbbfe0:
            return L"WBEMMOF_E_NULL_ARRAY_ELEM";
          case -0x7ffbbfdf:
            return L"WBEMMOF_E_DUPLICATE_QUALIFIER";
          case -0x7ffbbfde:
            return L"WBEMMOF_E_EXPECTED_FLAVOR_TYPE";
          case -0x7ffbbfdd:
            return L"WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES";
          case -0x7ffbbfdc:
            return L"WBEMMOF_E_MULTIPLE_ALIASES";
          case -0x7ffbbfdb:
            return L"WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES2";
          case -0x7ffbbfda:
            return L"WBEMMOF_E_NO_ARRAYS_RETURNED";
          case -0x7ffbbfd9:
            return L"WBEMMOF_E_MUST_BE_IN_OR_OUT";
          case -0x7ffbbfd8:
            return L"WBEMMOF_E_INVALID_FLAGS_SYNTAX";
          case -0x7ffbbfd7:
            return L"WBEMMOF_E_EXPECTED_BRACE_OR_BAD_TYPE";
          case -0x7ffbbfd6:
            return L"WBEMMOF_E_UNSUPPORTED_CIMV22_QUAL_VALUE";
          case -0x7ffbbfd5:
            return L"WBEMMOF_E_UNSUPPORTED_CIMV22_DATA_TYPE";
          case -0x7ffbbfd4:
            return L"WBEMMOF_E_INVALID_DELETEINSTANCE_SYNTAX";
          case -0x7ffbbfd3:
            return L"WBEMMOF_E_INVALID_QUALIFIER_SYNTAX";
          case -0x7ffbbfd2:
            return L"WBEMMOF_E_QUALIFIER_USED_OUTSIDE_SCOPE";
          case -0x7ffbbfd1:
            return L"WBEMMOF_E_ERROR_CREATING_TEMP_FILE";
          case -0x7ffbbfd0:
            return L"WBEMMOF_E_ERROR_INVALID_INCLUDE_FILE";
          case -0x7ffbbfcf:
            return L"WBEMMOF_E_INVALID_DELETECLASS_SYNTAX";
          }
        }
        else {
          switch(param_1) {
          case -0x7ffb2fff:
            return L"XACT_E_CANTRETAIN";
          case -0x7ffb2ffe:
            return L"XACT_E_COMMITFAILED";
          case -0x7ffb2ffd:
            return L"XACT_E_COMMITPREVENTED";
          case -0x7ffb2ffc:
            return L"XACT_E_HEURISTICABORT";
          case -0x7ffb2ffb:
            return L"XACT_E_HEURISTICCOMMIT";
          case -0x7ffb2ffa:
            return L"XACT_E_HEURISTICDAMAGE";
          case -0x7ffb2ff9:
            return L"XACT_E_HEURISTICDANGER";
          case -0x7ffb2ff8:
            return L"XACT_E_ISOLATIONLEVEL";
          }
        }
      }
      else if (param_1 < -0x7ffb2f7f) {
        if (param_1 == -0x7ffb2f80) {
          return L"XACT_E_CLERKNOTFOUND";
        }
        switch(param_1) {
        case -0x7ffb2ff6:
          return L"XACT_E_NOENLIST";
        case -0x7ffb2ff5:
          return L"XACT_E_NOISORETAIN";
        case -0x7ffb2ff4:
          return L"XACT_E_NORESOURCE";
        case -0x7ffb2ff3:
          return L"XACT_E_NOTCURRENT";
        case -0x7ffb2ff2:
          return L"XACT_E_NOTRANSACTION";
        case -0x7ffb2ff1:
          return L"XACT_E_NOTSUPPORTED";
        case -0x7ffb2ff0:
          return L"XACT_E_UNKNOWNRMGRID";
        case -0x7ffb2fef:
          return L"XACT_E_WRONGSTATE";
        case -0x7ffb2fee:
          return L"XACT_E_WRONGUOW";
        case -0x7ffb2fed:
          return L"XACT_E_XTIONEXISTS";
        case -0x7ffb2fec:
          return L"XACT_E_NOIMPORTOBJECT";
        case -0x7ffb2feb:
          return L"XACT_E_INVALIDCOOKIE";
        case -0x7ffb2fea:
          return L"XACT_E_INDOUBT";
        case -0x7ffb2fe9:
          return L"XACT_E_NOTIMEOUT";
        case -0x7ffb2fe8:
          return L"XACT_E_ALREADYINPROGRESS";
        case -0x7ffb2fe7:
          return L"XACT_E_ABORTED";
        case -0x7ffb2fe6:
          return L"XACT_E_LOGFULL";
        case -0x7ffb2fe5:
          return L"XACT_E_TMNOTAVAILABLE";
        case -0x7ffb2fe4:
          return L"XACT_E_CONNECTION_DOWN";
        case -0x7ffb2fe3:
          return L"XACT_E_CONNECTION_DENIED";
        case -0x7ffb2fe2:
          return L"XACT_E_REENLISTTIMEOUT";
        case -0x7ffb2fe1:
          return L"XACT_E_TIP_CONNECT_FAILED";
        case -0x7ffb2fe0:
          return L"XACT_E_TIP_PROTOCOL_ERROR";
        case -0x7ffb2fdf:
          return L"XACT_E_TIP_PULL_FAILED";
        case -0x7ffb2fde:
          return L"XACT_E_DEST_TMNOTAVAILABLE";
        case -0x7ffb2fdd:
          return L"XACT_E_TIP_DISABLED";
        case -0x7ffb2fdc:
          return L"XACT_E_NETWORK_TX_DISABLED";
        case -0x7ffb2fdb:
          return L"XACT_E_PARTNER_NETWORK_TX_DISABLED";
        case -0x7ffb2fda:
          return L"XACT_E_XA_TX_DISABLED";
        case -0x7ffb2fd9:
          return L"XACT_E_UNABLE_TO_READ_DTC_CONFIG";
        case -0x7ffb2fd8:
          return L"XACT_E_UNABLE_TO_LOAD_DTC_PROXY";
        case -0x7ffb2fd7:
          return L"XACT_E_LAST";
        }
      }
      else if (param_1 < -0x7ff8fb7c) {
        if (param_1 == -0x7ff8fb7d) {
LAB_0072eb40:
          return L"ERROR_NO_ASSOCIATION";
        }
        if (param_1 < -0x7ff8ff52) {
          if (param_1 == -0x7ff8ff53) {
LAB_0072e435:
            return L"ERROR_CANCEL_VIOLATION";
          }
          if (param_1 < -0x7ff8ffbe) {
            if (param_1 == -0x7ff8ffbf) {
LAB_0072e07e:
              return L"ERROR_NETWORK_ACCESS_DENIED";
            }
            if (param_1 < -0x7ff8fff2) {
              if (param_1 == -0x7ff8fff3) {
LAB_0072de7d:
                return L"ERROR_INVALID_DATA";
              }
              if (param_1 < -0x7ffb1fd7) {
                if (param_1 == -0x7ffb1fd8) {
                  return L"CO_E_THREADINGMODEL_CHANGED";
                }
                if (param_1 < -0x7ffb1ff8) {
                  if (param_1 == -0x7ffb1ff9) {
                    return L"CONTEXT_E_OLDREF";
                  }
                  if (param_1 < -0x7ffb1fff) {
                    if (param_1 == -0x7ffb2000) {
                      return L"CONTEXT_E_FIRST";
                    }
                    if (param_1 == -0x7ffb2f7f) {
                      return L"XACT_E_CLERKEXISTS";
                    }
                    if (param_1 == -0x7ffb2f7e) {
                      return L"XACT_E_RECOVERYINPROGRESS";
                    }
                    if (param_1 == -0x7ffb2f7d) {
                      return L"XACT_E_TRANSACTIONCLOSED";
                    }
                    if (param_1 == -0x7ffb2f7c) {
                      return L"XACT_E_INVALIDLSN";
                    }
                    if (param_1 == -0x7ffb2f7b) {
                      return L"XACT_E_REPLAYREQUEST";
                    }
                  }
                  else {
                    if (param_1 == -0x7ffb1ffe) {
                      return L"CONTEXT_E_ABORTED";
                    }
                    if (param_1 == -0x7ffb1ffd) {
                      return L"CONTEXT_E_ABORTING";
                    }
                    if (param_1 == -0x7ffb1ffc) {
                      return L"CONTEXT_E_NOCONTEXT";
                    }
                    if (param_1 == -0x7ffb1ffa) {
                      return L"CONTEXT_E_SYNCH_TIMEOUT";
                    }
                  }
                }
                else if (param_1 < -0x7ffb1fdc) {
                  if (param_1 == -0x7ffb1fdd) {
                    return L"CO_E_ACTIVATIONFAILED_CATALOGERROR";
                  }
                  if (param_1 == -0x7ffb1ff4) {
                    return L"CONTEXT_E_ROLENOTFOUND";
                  }
                  if (param_1 == -0x7ffb1ff1) {
                    return L"CONTEXT_E_TMNOTAVAILABLE";
                  }
                  if (param_1 == -0x7ffb1fdf) {
                    return L"CO_E_ACTIVATIONFAILED";
                  }
                  if (param_1 == -0x7ffb1fde) {
                    return L"CO_E_ACTIVATIONFAILED_EVENTLOGGED";
                  }
                }
                else {
                  if (param_1 == -0x7ffb1fdc) {
                    return L"CO_E_ACTIVATIONFAILED_TIMEOUT";
                  }
                  if (param_1 == -0x7ffb1fdb) {
                    return L"CO_E_INITIALIZATIONFAILED";
                  }
                  if (param_1 == -0x7ffb1fda) {
                    return L"CONTEXT_E_NOJIT";
                  }
                  if (param_1 == -0x7ffb1fd9) {
                    return L"CONTEXT_E_NOTRANSACTION";
                  }
                }
              }
              else if (param_1 < -0x7ff8fffc) {
                if (param_1 == -0x7ff8fffd) {
LAB_0072de1a:
                  return L"ERROR_PATH_NOT_FOUND";
                }
                if (param_1 < -0x7ffb1fd2) {
                  if (param_1 == -0x7ffb1fd3) {
                    return L"CO_E_NOTCONSTRUCTED";
                  }
                  if (param_1 == -0x7ffb1fd7) {
                    return L"CO_E_NOIISINTRINSICS";
                  }
                  if (param_1 == -0x7ffb1fd6) {
                    return L"CO_E_NOCOOKIES";
                  }
                  if (param_1 == -0x7ffb1fd5) {
                    return L"CO_E_DBERROR";
                  }
                  if (param_1 == -0x7ffb1fd4) {
                    return L"CO_E_NOTPOOLED";
                  }
                }
                else {
                  if (param_1 == -0x7ffb1fd2) {
                    return L"CO_E_NOSYNCHRONIZATION";
                  }
                  if (param_1 == -0x7ffb1fd1) {
                    return L"CONTEXT_E_LAST";
                  }
                  if (param_1 == -0x7ff8ffff) {
                    return L"ERROR_INVALID_FUNCTION";
                  }
                  if (param_1 == -0x7ff8fffe) {
LAB_00729b6b:
                    return L"ERROR_FILE_NOT_FOUND";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ff8fffc:
LAB_0072de10:
                  return L"ERROR_TOO_MANY_OPEN_FILES";
                case -0x7ff8fffb:
                  return L"E_ACCESSDENIED";
                case -0x7ff8fffa:
                  return L"E_HANDLE";
                case -0x7ff8fff9:
code_r0x0072de41:
                  return L"ERROR_ARENA_TRASHED";
                case -0x7ff8fff8:
code_r0x0072de4b:
                  return L"ERROR_NOT_ENOUGH_MEMORY";
                case -0x7ff8fff7:
code_r0x0072de55:
                  return L"ERROR_INVALID_BLOCK";
                case -0x7ff8fff6:
code_r0x0072de5f:
                  return L"ERROR_BAD_ENVIRONMENT";
                case -0x7ff8fff5:
code_r0x0072de69:
                  return L"ERROR_BAD_FORMAT";
                case -0x7ff8fff4:
code_r0x0072de73:
                  return L"ERROR_INVALID_ACCESS & DIERR_NOTACQUIRED";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8fff2:
                return L"E_OUTOFMEMORY";
              case -0x7ff8fff1:
code_r0x0072de91:
                return L"ERROR_INVALID_DRIVE";
              case -0x7ff8fff0:
LAB_0072de9b:
                return L"ERROR_CURRENT_DIRECTORY";
              case -0x7ff8ffef:
code_r0x0072deb8:
                return L"ERROR_NOT_SAME_DEVICE";
              case -0x7ff8ffee:
code_r0x0072dec2:
                return L"ERROR_NO_MORE_FILES";
              case -0x7ff8ffed:
code_r0x0072decc:
                return L"ERROR_WRITE_PROTECT";
              case -0x7ff8ffec:
code_r0x0072ded6:
                return L"ERROR_BAD_UNIT";
              case -0x7ff8ffeb:
code_r0x0072dee0:
                return L"ERROR_NOT_READY & DIERR_NOTINITIALIZED";
              case -0x7ff8ffea:
code_r0x0072deea:
                return L"ERROR_BAD_COMMAND";
              case -0x7ff8ffe9:
code_r0x0072def4:
                return L"ERROR_CRC";
              case -0x7ff8ffe8:
code_r0x0072defe:
                return L"ERROR_BAD_LENGTH";
              case -0x7ff8ffe7:
code_r0x0072df08:
                return L"ERROR_SEEK";
              case -0x7ff8ffe6:
code_r0x0072df12:
                return L"ERROR_NOT_DOS_DISK";
              case -0x7ff8ffe5:
code_r0x0072df1c:
                return L"ERROR_SECTOR_NOT_FOUND";
              case -0x7ff8ffe4:
code_r0x0072df26:
                return L"ERROR_OUT_OF_PAPER";
              case -0x7ff8ffe3:
code_r0x0072df30:
                return L"ERROR_WRITE_FAULT";
              case -0x7ff8ffe2:
code_r0x0072df3a:
                return L"ERROR_READ_FAULT & DIERR_INPUTLOST";
              case -0x7ff8ffe1:
code_r0x0072df44:
                return L"ERROR_GEN_FAILURE";
              case -0x7ff8ffe0:
code_r0x0072df4e:
                return L"ERROR_SHARING_VIOLATION";
              case -0x7ff8ffdf:
code_r0x0072df58:
                return L"ERROR_LOCK_VIOLATION";
              case -0x7ff8ffde:
code_r0x0072df62:
                return L"ERROR_WRONG_DISK";
              case -0x7ff8ffdc:
code_r0x0072df6c:
                return L"ERROR_SHARING_BUFFER_EXCEEDED";
              case -0x7ff8ffda:
LAB_0072df76:
                return L"ERROR_HANDLE_EOF";
              case -0x7ff8ffd9:
LAB_0072dfd7:
                return L"ERROR_HANDLE_DISK_FULL";
              case -0x7ff8ffce:
LAB_0072dfcd:
                return L"ERROR_NOT_SUPPORTED";
              case -0x7ff8ffcd:
LAB_0072dfc3:
                return L"ERROR_REM_NOT_LIST";
              case -0x7ff8ffcc:
code_r0x0072dfb9:
                return L"ERROR_DUP_NAME";
              case -0x7ff8ffcb:
LAB_0072dfe1:
                return L"ERROR_BAD_NETPATH";
              case -0x7ff8ffca:
LAB_0072e01b:
                return L"ERROR_NETWORK_BUSY";
              case -0x7ff8ffc9:
LAB_0072e011:
                return L"ERROR_DEV_NOT_EXIST";
              case -0x7ff8ffc8:
LAB_0072e007:
                return L"ERROR_TOO_MANY_CMDS";
              case -0x7ff8ffc7:
code_r0x0072dffd:
                return L"ERROR_ADAP_HDW_ERR";
              case -0x7ff8ffc6:
LAB_0072e025:
                return L"ERROR_BAD_NET_RESP";
              case -0x7ff8ffc5:
code_r0x0072e042:
                return L"ERROR_UNEXP_NET_ERR";
              case -0x7ff8ffc4:
code_r0x0072e04c:
                return L"ERROR_BAD_REM_ADAP";
              case -0x7ff8ffc3:
code_r0x0072e056:
                return L"ERROR_PRINTQ_FULL";
              case -0x7ff8ffc2:
code_r0x0072e060:
                return L"ERROR_NO_SPOOL_SPACE";
              case -0x7ff8ffc1:
code_r0x0072e06a:
                return L"ERROR_PRINT_CANCELLED";
              case -0x7ff8ffc0:
code_r0x0072e074:
                return L"ERROR_NETNAME_DELETED";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ff8ffbe:
code_r0x0072e088:
              return L"ERROR_BAD_DEV_TYPE";
            case -0x7ff8ffbd:
code_r0x0072e092:
              return L"ERROR_BAD_NET_NAME";
            case -0x7ff8ffbc:
LAB_0072e09c:
              return L"ERROR_TOO_MANY_NAMES";
            case -0x7ff8ffbb:
LAB_0072e0ec:
              return L"ERROR_TOO_MANY_SESS";
            case -0x7ff8ffba:
LAB_0072e0e2:
              return L"ERROR_SHARING_PAUSED";
            case -0x7ff8ffb9:
LAB_0072e0d8:
              return L"ERROR_REQ_NOT_ACCEP";
            case -0x7ff8ffb8:
code_r0x0072e0ce:
              return L"ERROR_REDIR_PAUSED";
            case -0x7ff8ffb0:
LAB_0072e0f6:
              return L"ERROR_FILE_EXISTS";
            case -0x7ff8ffae:
LAB_0072e130:
              return L"ERROR_CANNOT_MAKE";
            case -0x7ff8ffad:
LAB_0072e126:
              return L"ERROR_FAIL_I24";
            case -0x7ff8ffac:
LAB_0072e11c:
              return L"ERROR_OUT_OF_STRUCTURES";
            case -0x7ff8ffab:
code_r0x0072e112:
              return L"ERROR_ALREADY_ASSIGNED";
            case -0x7ff8ffaa:
LAB_0072e13a:
              return L"ERROR_INVALID_PASSWORD";
            case -0x7ff8ffa9:
              return L"E_INVALIDARG";
            case -0x7ff8ffa8:
LAB_0072e173:
              return L"ERROR_NET_WRITE_FAULT";
            case -0x7ff8ffa7:
LAB_0072e169:
              return L"ERROR_NO_PROC_SLOTS";
            case -0x7ff8ff9c:
code_r0x0072e15f:
              return L"ERROR_TOO_MANY_SEMAPHORES";
            case -0x7ff8ff9b:
LAB_0072e187:
              return L"ERROR_EXCL_SEM_ALREADY_OWNED";
            case -0x7ff8ff9a:
LAB_0072e1c1:
              return L"ERROR_SEM_IS_SET";
            case -0x7ff8ff99:
LAB_0072e1b7:
              return L"ERROR_TOO_MANY_SEM_REQUESTS";
            case -0x7ff8ff98:
LAB_0072e1ad:
              return L"ERROR_INVALID_AT_INTERRUPT_TIME";
            case -0x7ff8ff97:
code_r0x0072e1a3:
              return L"ERROR_SEM_OWNER_DIED";
            case -0x7ff8ff96:
              goto LAB_0072e1cb;
            case -0x7ff8ff95:
code_r0x0072e1fb:
              return L"ERROR_DISK_CHANGE";
            case -0x7ff8ff94:
code_r0x0072e205:
              return L"ERROR_DRIVE_LOCKED";
            case -0x7ff8ff93:
code_r0x0072e20f:
              return L"ERROR_BROKEN_PIPE";
            case -0x7ff8ff92:
code_r0x0072e219:
              return L"ERROR_OPEN_FAILED";
            case -0x7ff8ff91:
code_r0x0072e223:
              return L"ERROR_BUFFER_OVERFLOW";
            case -0x7ff8ff90:
code_r0x0072e22d:
              return L"ERROR_DISK_FULL";
            case -0x7ff8ff8f:
code_r0x0072e237:
              return L"ERROR_NO_MORE_SEARCH_HANDLES";
            case -0x7ff8ff8e:
code_r0x0072e241:
              return L"ERROR_INVALID_TARGET_HANDLE";
            case -0x7ff8ff8b:
code_r0x0072e24b:
              return L"ERROR_INVALID_CATEGORY";
            case -0x7ff8ff8a:
code_r0x0072e255:
              return L"ERROR_INVALID_VERIFY_SWITCH";
            case -0x7ff8ff89:
code_r0x0072e25f:
              return L"ERROR_BAD_DRIVER_LEVEL & DIERR_BADDRIVERVER";
            case -0x7ff8ff88:
code_r0x0072e269:
              return L"ERROR_CALL_NOT_IMPLEMENTED";
            case -0x7ff8ff87:
code_r0x0072e273:
              return L"ERROR_SEM_TIMEOUT";
            case -0x7ff8ff86:
code_r0x0072e27d:
              return L"ERROR_INSUFFICIENT_BUFFER";
            case -0x7ff8ff85:
code_r0x0072e287:
              return L"ERROR_INVALID_NAME";
            case -0x7ff8ff84:
code_r0x0072e291:
              return L"ERROR_INVALID_LEVEL";
            case -0x7ff8ff83:
code_r0x0072e29b:
              return L"ERROR_NO_VOLUME_LABEL";
            case -0x7ff8ff82:
code_r0x0072e2a5:
              return L"ERROR_MOD_NOT_FOUND";
            case -0x7ff8ff81:
code_r0x0072e2af:
              return L"ERROR_PROC_NOT_FOUND";
            case -0x7ff8ff80:
code_r0x0072e2b9:
              return L"ERROR_WAIT_NO_CHILDREN";
            case -0x7ff8ff7f:
code_r0x0072e2c3:
              return L"ERROR_CHILD_NOT_COMPLETE";
            case -0x7ff8ff7e:
code_r0x0072e2cd:
              return L"ERROR_DIRECT_ACCESS_HANDLE";
            case -0x7ff8ff7d:
code_r0x0072e2d7:
              return L"ERROR_NEGATIVE_SEEK";
            case -0x7ff8ff7c:
code_r0x0072e2e1:
              return L"ERROR_SEEK_ON_DEVICE";
            case -0x7ff8ff7b:
code_r0x0072e2eb:
              return L"ERROR_IS_JOIN_TARGET";
            case -0x7ff8ff7a:
code_r0x0072e2f5:
              return L"ERROR_IS_JOINED";
            case -0x7ff8ff79:
code_r0x0072e2ff:
              return L"ERROR_IS_SUBSTED";
            case -0x7ff8ff78:
code_r0x0072e309:
              return L"ERROR_NOT_JOINED";
            case -0x7ff8ff77:
code_r0x0072e313:
              return L"ERROR_NOT_SUBSTED";
            case -0x7ff8ff76:
code_r0x0072e31d:
              return L"ERROR_JOIN_TO_JOIN";
            case -0x7ff8ff75:
code_r0x0072e327:
              return L"ERROR_SUBST_TO_SUBST";
            case -0x7ff8ff74:
code_r0x0072e331:
              return L"ERROR_JOIN_TO_SUBST";
            case -0x7ff8ff73:
code_r0x0072e33b:
              return L"ERROR_SUBST_TO_JOIN";
            case -0x7ff8ff72:
code_r0x0072e345:
              return L"ERROR_BUSY_DRIVE";
            case -0x7ff8ff71:
code_r0x0072e34f:
              return L"ERROR_SAME_DRIVE";
            case -0x7ff8ff70:
code_r0x0072e359:
              return L"ERROR_DIR_NOT_ROOT";
            case -0x7ff8ff6f:
code_r0x0072e363:
              return L"ERROR_DIR_NOT_EMPTY";
            case -0x7ff8ff6e:
code_r0x0072e36d:
              return L"ERROR_IS_SUBST_PATH";
            case -0x7ff8ff6d:
code_r0x0072e377:
              return L"ERROR_IS_JOIN_PATH";
            case -0x7ff8ff6c:
code_r0x0072e381:
              return L"ERROR_PATH_BUSY";
            case -0x7ff8ff6b:
code_r0x0072e38b:
              return L"ERROR_IS_SUBST_TARGET";
            case -0x7ff8ff6a:
code_r0x0072e395:
              return L"ERROR_SYSTEM_TRACE";
            case -0x7ff8ff69:
code_r0x0072e39f:
              return L"ERROR_INVALID_EVENT_COUNT";
            case -0x7ff8ff68:
code_r0x0072e3a9:
              return L"ERROR_TOO_MANY_MUXWAITERS";
            case -0x7ff8ff67:
code_r0x0072e3b3:
              return L"ERROR_INVALID_LIST_FORMAT";
            case -0x7ff8ff66:
code_r0x0072e3bd:
              return L"ERROR_LABEL_TOO_LONG";
            case -0x7ff8ff65:
code_r0x0072e3c7:
              return L"ERROR_TOO_MANY_TCBS";
            case -0x7ff8ff64:
code_r0x0072e3d1:
              return L"ERROR_SIGNAL_REFUSED";
            case -0x7ff8ff63:
code_r0x0072e3db:
              return L"ERROR_DISCARDED";
            case -0x7ff8ff62:
code_r0x0072e3e5:
              return L"ERROR_NOT_LOCKED";
            case -0x7ff8ff61:
code_r0x0072e3ef:
              return L"ERROR_BAD_THREADID_ADDR";
            case -0x7ff8ff60:
code_r0x0072e3f9:
              return L"ERROR_BAD_ARGUMENTS";
            case -0x7ff8ff5f:
code_r0x0072e403:
              return L"ERROR_BAD_PATHNAME";
            case -0x7ff8ff5e:
code_r0x0072e40d:
              return L"ERROR_SIGNAL_PENDING";
            case -0x7ff8ff5c:
code_r0x0072e417:
              return L"ERROR_MAX_THRDS_REACHED";
            case -0x7ff8ff59:
code_r0x0072e421:
              return L"ERROR_LOCK_FAILED";
            case -0x7ff8ff56:
code_r0x0072e42b:
              return L"ERROR_BUSY & DIERR_ACQUIRED";
            }
          }
        }
        else if (param_1 < -0x7ff8fc07) {
          if (param_1 == -0x7ff8fc08) {
LAB_0072e7ff:
            return L"ERROR_REGISTRY_IO_FAILED";
          }
          if (param_1 < -0x7ff8fef5) {
            if (param_1 == -0x7ff8fef6) {
LAB_0072e625:
              return L"ERROR_CANNOT_COPY";
            }
            switch(param_1) {
            case -0x7ff8ff52:
              goto code_r0x0072e43f;
            case -0x7ff8ff4c:
              goto code_r0x0072e449;
            case -0x7ff8ff4a:
              goto code_r0x0072e453;
            case -0x7ff8ff49:
              goto code_r0x0072e45d;
            case -0x7ff8ff46:
              goto code_r0x0072e467;
            case -0x7ff8ff45:
              goto code_r0x0072e471;
            case -0x7ff8ff44:
              goto code_r0x0072e47b;
            case -0x7ff8ff43:
              goto code_r0x0072e485;
            case -0x7ff8ff42:
              goto code_r0x0072e48f;
            case -0x7ff8ff41:
              goto code_r0x0072e499;
            case -0x7ff8ff40:
              goto code_r0x0072e4a3;
            case -0x7ff8ff3f:
              goto code_r0x0072e4ad;
            case -0x7ff8ff3e:
              goto code_r0x0072e4b7;
            case -0x7ff8ff3d:
              goto code_r0x0072e4c1;
            case -0x7ff8ff3c:
              goto code_r0x0072e4cb;
            case -0x7ff8ff3b:
              goto code_r0x0072e4d5;
            case -0x7ff8ff3a:
              goto code_r0x0072e4df;
            case -0x7ff8ff39:
              goto code_r0x0072e4e9;
            case -0x7ff8ff36:
              goto code_r0x0072e507;
            case -0x7ff8ff35:
              goto code_r0x0072e511;
            case -0x7ff8ff33:
              goto code_r0x0072e51b;
            case -0x7ff8ff32:
              goto code_r0x0072e525;
            case -0x7ff8ff31:
              goto code_r0x0072e52f;
            case -0x7ff8ff30:
              goto code_r0x0072e539;
            case -0x7ff8ff2f:
              goto code_r0x0072e543;
            case -0x7ff8ff2e:
              goto code_r0x0072e54d;
            case -0x7ff8ff2c:
              goto code_r0x0072e557;
            case -0x7ff8ff2a:
              goto code_r0x0072e561;
            case -0x7ff8ff29:
              goto code_r0x0072e56b;
            case -0x7ff8ff28:
              goto code_r0x0072e575;
            case -0x7ff8ff1a:
              goto code_r0x0072e57f;
            case -0x7ff8ff19:
              goto code_r0x0072e589;
            case -0x7ff8ff18:
              goto code_r0x0072e593;
            case -0x7ff8ff17:
              goto code_r0x0072e59d;
            case -0x7ff8ff16:
              goto code_r0x0072e5a7;
            case -0x7ff8ff10:
              goto LAB_0072e5b1;
            case -0x7ff8ff02:
code_r0x0072e5fd:
              return L"ERROR_INVALID_EA_NAME";
            case -0x7ff8ff01:
code_r0x0072e607:
              return L"ERROR_EA_LIST_INCONSISTENT";
            case -0x7ff8fefe:
code_r0x0072e611:
              return L"WAIT_TIMEOUT";
            case -0x7ff8fefd:
code_r0x0072e61b:
              return L"ERROR_NO_MORE_ITEMS & DIERR_NOMOREITEMS";
            }
          }
          else if (param_1 < -0x7ff8fc1c) {
            if (param_1 == -0x7ff8fc1d) {
LAB_0072e757:
              return L"ERROR_OPERATION_ABORTED";
            }
            if (param_1 < -0x7ff8fed3) {
              if (param_1 == -0x7ff8fed4) {
LAB_0072e675:
                return L"ERROR_OPLOCK_NOT_GRANTED";
              }
              if (param_1 < -0x7ff8fee9) {
                if (param_1 == -0x7ff8feea) goto LAB_0072e64d;
                if (param_1 == -0x7ff8fef5) goto LAB_0072e62f;
                if (param_1 == -0x7ff8feed) goto LAB_0072e639;
                if (param_1 == -0x7ff8feec) goto LAB_0072e643;
                if (param_1 == -0x7ff8feeb) goto code_r0x00729c93;
              }
              else {
                if (param_1 == -0x7ff8fee6) goto LAB_0072e657;
                if (param_1 == -0x7ff8fee0) goto LAB_0072e661;
                if (param_1 == -0x7ff8fed6) goto LAB_0072e66b;
                if (param_1 == -0x7ff8fed5) goto code_r0x00729cc9;
              }
            }
            else if (param_1 < -0x7ff8fe18) {
              if (param_1 == -0x7ff8fe19) {
LAB_0072e6df:
                return L"ERROR_INVALID_ADDRESS";
              }
              if (param_1 == -0x7ff8fed3) goto LAB_0072e67f;
              if (param_1 == -0x7ff8fed2) goto LAB_0072e6f3;
              if (param_1 == -0x7ff8fed1) goto LAB_0072e6e9;
              if (param_1 == -0x7ff8fec3) goto LAB_00729d0e;
            }
            else {
              if (param_1 == -0x7ff8fdea) {
LAB_0072e6d5:
                return L"ERROR_ARITHMETIC_OVERFLOW";
              }
              if (param_1 == -0x7ff8fde9) {
LAB_0072e6cb:
                return L"ERROR_PIPE_CONNECTED";
              }
              if (param_1 == -0x7ff8fde8) {
LAB_0072e6c1:
                return L"ERROR_PIPE_LISTENING";
              }
              if (param_1 == -0x7ff8fc1e) goto LAB_00729d44;
            }
          }
          else {
            switch(param_1) {
            case -0x7ff8fc1c:
LAB_0072e74d:
              return L"ERROR_IO_INCOMPLETE";
            case -0x7ff8fc1b:
LAB_0072e743:
              return L"ERROR_IO_PENDING";
            case -0x7ff8fc1a:
LAB_0072e739:
              return L"ERROR_NOACCESS";
            case -0x7ff8fc19:
LAB_0072e72f:
              return L"ERROR_SWAPERROR";
            case -0x7ff8fc17:
LAB_0072e725:
              return L"ERROR_STACK_OVERFLOW";
            case -0x7ff8fc16:
code_r0x0072e71b:
              return L"ERROR_INVALID_MESSAGE";
            case -0x7ff8fc15:
              goto LAB_0072e761;
            case -0x7ff8fc14:
              goto LAB_0072e787;
            case -0x7ff8fc13:
              goto LAB_0072e791;
            case -0x7ff8fc12:
              goto LAB_0072e79b;
            case -0x7ff8fc11:
              goto LAB_0072e7a5;
            case -0x7ff8fc10:
              goto LAB_0072e7af;
            case -0x7ff8fc0f:
              goto LAB_0072e7b9;
            case -0x7ff8fc0e:
              goto LAB_0072e7c3;
            case -0x7ff8fc0d:
              goto LAB_0072e7cd;
            case -0x7ff8fc0c:
              goto LAB_0072e7d7;
            case -0x7ff8fc0b:
              goto LAB_0072e7e1;
            case -0x7ff8fc0a:
              goto LAB_0072e7eb;
            case -0x7ff8fc09:
              goto LAB_0072e7f5;
            }
          }
        }
        else {
          switch(param_1) {
          case -0x7ff8fc07:
LAB_0072e809:
            return L"ERROR_NOT_REGISTRY_FILE";
          case -0x7ff8fc06:
LAB_0072e813:
            return L"ERROR_KEY_DELETED";
          case -0x7ff8fc05:
LAB_0072e81d:
            return L"ERROR_NO_LOG_SPACE";
          case -0x7ff8fc04:
LAB_0072e827:
            return L"ERROR_KEY_HAS_CHILDREN";
          case -0x7ff8fc03:
LAB_0072e831:
            return L"ERROR_CHILD_MUST_BE_VOLATILE";
          case -0x7ff8fc02:
LAB_0072e83b:
            return L"ERROR_NOTIFY_ENUM_DIR";
          case -0x7ff8fbe5:
LAB_0072e845:
            return L"ERROR_DEPENDENT_SERVICES_RUNNING";
          case -0x7ff8fbe4:
LAB_0072e84f:
            return L"ERROR_INVALID_SERVICE_CONTROL";
          case -0x7ff8fbe3:
LAB_0072e859:
            return L"ERROR_SERVICE_REQUEST_TIMEOUT";
          case -0x7ff8fbe2:
LAB_0072e863:
            return L"ERROR_SERVICE_NO_THREAD";
          case -0x7ff8fbe1:
LAB_0072e86d:
            return L"ERROR_SERVICE_DATABASE_LOCKED";
          case -0x7ff8fbe0:
LAB_0072e877:
            return L"ERROR_SERVICE_ALREADY_RUNNING";
          case -0x7ff8fbdf:
LAB_0072e881:
            return L"ERROR_INVALID_SERVICE_ACCOUNT";
          case -0x7ff8fbde:
LAB_0072e88b:
            return L"ERROR_SERVICE_DISABLED";
          case -0x7ff8fbdd:
LAB_0072e895:
            return L"ERROR_CIRCULAR_DEPENDENCY";
          case -0x7ff8fbdc:
LAB_0072e89f:
            return L"ERROR_SERVICE_DOES_NOT_EXIST";
          case -0x7ff8fbdb:
LAB_0072e8a9:
            return L"ERROR_SERVICE_CANNOT_ACCEPT_CTRL";
          case -0x7ff8fbda:
            goto LAB_0072e8b3;
          case -0x7ff8fbd9:
            goto LAB_0072e8d4;
          case -0x7ff8fbd8:
            goto LAB_0072e8de;
          case -0x7ff8fbd7:
            goto LAB_0072e8e8;
          case -0x7ff8fbd6:
            goto LAB_0072e8f2;
          case -0x7ff8fbd5:
            goto LAB_0072e8fc;
          case -0x7ff8fbd4:
            goto LAB_0072e906;
          case -0x7ff8fbd3:
            goto LAB_0072e910;
          case -0x7ff8fbd2:
            goto LAB_0072e91a;
          case -0x7ff8fbd1:
            goto LAB_0072e924;
          case -0x7ff8fbd0:
            goto LAB_0072e92e;
          case -0x7ff8fbcf:
            goto LAB_0072e938;
          case -0x7ff8fbce:
            goto LAB_0072e942;
          case -0x7ff8fbcd:
            goto LAB_0072e94c;
          case -0x7ff8fbcc:
            goto LAB_0072e956;
          case -0x7ff8fbcb:
            goto LAB_0072e960;
          case -0x7ff8fbca:
            goto LAB_0072e96a;
          case -0x7ff8fbc9:
            goto LAB_0072e974;
          case -0x7ff8fbc8:
            goto LAB_0072e97e;
          case -0x7ff8fbc7:
            goto LAB_0072e988;
          case -0x7ff8fbc6:
            goto LAB_0072e992;
          case -0x7ff8fbc5:
            goto LAB_0072e99c;
          case -0x7ff8fbb4:
            goto LAB_0072e9a6;
          case -0x7ff8fbb3:
            goto LAB_0072e9b0;
          case -0x7ff8fbb2:
            goto LAB_0072e9ba;
          case -0x7ff8fbb1:
            goto LAB_0072e9c4;
          case -0x7ff8fbb0:
            goto LAB_0072e9ce;
          case -0x7ff8fbaf:
            goto LAB_0072e9d8;
          case -0x7ff8fbae:
            goto LAB_0072e9e2;
          case -0x7ff8fbad:
            goto LAB_0072e9ec;
          case -0x7ff8fbac:
            goto LAB_0072e9f6;
          case -0x7ff8fbab:
            goto LAB_0072ea00;
          case -0x7ff8fbaa:
            goto LAB_0072ea0a;
          case -0x7ff8fba9:
            goto LAB_0072ea14;
          case -0x7ff8fba8:
            goto LAB_0072ea1e;
          case -0x7ff8fba7:
            goto LAB_0072ea28;
          case -0x7ff8fba6:
            goto LAB_0072ea32;
          case -0x7ff8fba5:
            goto LAB_0072ea3c;
          case -0x7ff8fba4:
            goto LAB_0072ea46;
          case -0x7ff8fba3:
            goto LAB_0072ea50;
          case -0x7ff8fba2:
            goto LAB_0072ea5a;
          case -0x7ff8fba1:
            goto LAB_0072ea64;
          case -0x7ff8fba0:
            goto LAB_0072ea6e;
          case -0x7ff8fb9f:
            goto LAB_0072ea78;
          case -0x7ff8fb9e:
            goto LAB_0072ea82;
          case -0x7ff8fb9d:
            goto LAB_0072ea8c;
          case -0x7ff8fb9c:
            goto LAB_0072ea96;
          case -0x7ff8fb9b:
            goto LAB_0072eaa0;
          case -0x7ff8fb9a:
            goto LAB_0072eaaa;
          case -0x7ff8fb99:
            goto LAB_0072eab4;
          case -0x7ff8fb98:
            goto LAB_0072eabe;
          case -0x7ff8fb97:
            goto LAB_0072eac8;
          case -0x7ff8fb96:
            goto LAB_0072ead2;
          case -0x7ff8fb95:
            goto LAB_0072eadc;
          case -0x7ff8fb94:
            goto LAB_0072eae6;
          case -0x7ff8fb8c:
            goto LAB_0072eaf0;
          case -0x7ff8fb8b:
            goto LAB_0072eafa;
          case -0x7ff8fb8a:
            goto LAB_0072eb04;
          case -0x7ff8fb82:
            goto LAB_0072eb0e;
          case -0x7ff8fb81:
            goto LAB_0072eb18;
          case -0x7ff8fb80:
            goto LAB_0072eb22;
          case -0x7ff8fb7f:
            goto LAB_0072eb2c;
          case -0x7ff8fb7e:
            goto LAB_0072eb36;
          }
        }
      }
      else {
        switch(param_1) {
        case -0x7ff8fb7c:
code_r0x0072eb4a:
          return L"ERROR_DDE_FAIL";
        case -0x7ff8fb7b:
code_r0x0072eb54:
          return L"ERROR_DLL_NOT_FOUND";
        case -0x7ff8fb7a:
code_r0x0072eb5e:
          return L"ERROR_NO_MORE_USER_HANDLES";
        case -0x7ff8fb79:
code_r0x0072eb68:
          return L"ERROR_MESSAGE_SYNC_ONLY";
        case -0x7ff8fb78:
code_r0x0072eb72:
          return L"ERROR_SOURCE_ELEMENT_EMPTY";
        case -0x7ff8fb77:
code_r0x0072eb7c:
          return L"ERROR_DESTINATION_ELEMENT_FULL";
        case -0x7ff8fb76:
code_r0x0072eb86:
          return L"ERROR_ILLEGAL_ELEMENT_ADDRESS";
        case -0x7ff8fb75:
code_r0x0072eb90:
          return L"ERROR_MAGAZINE_NOT_PRESENT";
        case -0x7ff8fb74:
code_r0x0072eb9a:
          return L"ERROR_DEVICE_REINITIALIZATION_NEEDED";
        case -0x7ff8fb73:
code_r0x0072eba4:
          return L"ERROR_DEVICE_REQUIRES_CLEANING";
        case -0x7ff8fb72:
code_r0x0072ebae:
          return L"ERROR_DEVICE_DOOR_OPEN";
        case -0x7ff8fb71:
code_r0x0072ebb8:
          return L"ERROR_DEVICE_NOT_CONNECTED";
        case -0x7ff8fb70:
code_r0x0072ebc2:
          return L"ERROR_NOT_FOUND & E_PROP_ID_UNSUPPORTED";
        case -0x7ff8fb6f:
code_r0x0072ebcc:
          return L"ERROR_NO_MATCH";
        case -0x7ff8fb6e:
code_r0x0072ebd6:
          return L"ERROR_SET_NOT_FOUND & E_PROP_SET_UNSUPPORTED";
        case -0x7ff8fb6d:
code_r0x0072ebe0:
          return L"ERROR_POINT_NOT_FOUND";
        case -0x7ff8fb6c:
code_r0x0072ebea:
          return L"ERROR_NO_TRACKING_SERVICE";
        case -0x7ff8fb6b:
code_r0x0072ebf4:
          return L"ERROR_NO_VOLUME_ID";
        case -0x7ff8fb69:
code_r0x0072ebfe:
          return L"ERROR_UNABLE_TO_REMOVE_REPLACED";
        case -0x7ff8fb68:
code_r0x0072ec08:
          return L"ERROR_UNABLE_TO_MOVE_REPLACEMENT";
        case -0x7ff8fb67:
code_r0x0072ec12:
          return L"ERROR_UNABLE_TO_MOVE_REPLACEMENT_2";
        case -0x7ff8fb66:
code_r0x0072ec1c:
          return L"ERROR_JOURNAL_DELETE_IN_PROGRESS";
        case -0x7ff8fb65:
code_r0x0072ec26:
          return L"ERROR_JOURNAL_NOT_ACTIVE";
        case -0x7ff8fb64:
code_r0x0072ec30:
          return L"ERROR_POTENTIAL_FILE_FOUND";
        case -0x7ff8fb63:
code_r0x0072f45a:
          return L"ERROR_JOURNAL_ENTRY_DELETED";
        case -0x7ff8fb50:
code_r0x0072ec3a:
          return L"ERROR_BAD_DEVICE";
        case -0x7ff8fb4f:
code_r0x0072ec44:
          return L"ERROR_CONNECTION_UNAVAIL";
        case -0x7ff8fb4e:
code_r0x0072ec4e:
          return L"ERROR_DEVICE_ALREADY_REMEMBERED";
        case -0x7ff8fb4d:
code_r0x0072ec58:
          return L"ERROR_NO_NET_OR_BAD_PATH";
        case -0x7ff8fb4c:
code_r0x0072ec62:
          return L"ERROR_BAD_PROVIDER";
        case -0x7ff8fb4b:
code_r0x0072ec6c:
          return L"ERROR_CANNOT_OPEN_PROFILE";
        case -0x7ff8fb4a:
code_r0x0072ec76:
          return L"ERROR_BAD_PROFILE";
        case -0x7ff8fb49:
code_r0x0072ec80:
          return L"ERROR_NOT_CONTAINER";
        case -0x7ff8fb48:
code_r0x0072ec8a:
          return L"ERROR_EXTENDED_ERROR";
        case -0x7ff8fb47:
code_r0x0072ec94:
          return L"ERROR_INVALID_GROUPNAME";
        case -0x7ff8fb46:
code_r0x0072ec9e:
          return L"ERROR_INVALID_COMPUTERNAME";
        case -0x7ff8fb45:
code_r0x0072eca8:
          return L"ERROR_INVALID_EVENTNAME";
        case -0x7ff8fb44:
code_r0x0072ecb2:
          return L"ERROR_INVALID_DOMAINNAME";
        case -0x7ff8fb43:
code_r0x0072ecbc:
          return L"ERROR_INVALID_SERVICENAME";
        case -0x7ff8fb42:
code_r0x0072ecc6:
          return L"ERROR_INVALID_NETNAME";
        case -0x7ff8fb41:
code_r0x0072ecd0:
          return L"ERROR_INVALID_SHARENAME";
        case -0x7ff8fb40:
code_r0x0072ecda:
          return L"ERROR_INVALID_PASSWORDNAME";
        case -0x7ff8fb3f:
code_r0x0072ece4:
          return L"ERROR_INVALID_MESSAGENAME";
        case -0x7ff8fb3e:
code_r0x0072ecee:
          return L"ERROR_INVALID_MESSAGEDEST";
        case -0x7ff8fb3d:
code_r0x0072ecf8:
          return L"ERROR_SESSION_CREDENTIAL_CONFLICT";
        case -0x7ff8fb3c:
code_r0x0072ed02:
          return L"ERROR_REMOTE_SESSION_LIMIT_EXCEEDED";
        case -0x7ff8fb3b:
code_r0x0072ed0c:
          return L"ERROR_DUP_DOMAINNAME";
        case -0x7ff8fb3a:
code_r0x0072ed16:
          return L"ERROR_NO_NETWORK";
        case -0x7ff8fb39:
code_r0x0072ed20:
          return L"ERROR_CANCELLED";
        case -0x7ff8fb38:
code_r0x0072ed2a:
          return L"ERROR_USER_MAPPED_FILE";
        case -0x7ff8fb37:
code_r0x0072ed34:
          return L"ERROR_CONNECTION_REFUSED";
        case -0x7ff8fb36:
code_r0x0072ed3e:
          return L"ERROR_GRACEFUL_DISCONNECT";
        case -0x7ff8fb35:
code_r0x0072ed48:
          return L"ERROR_ADDRESS_ALREADY_ASSOCIATED";
        case -0x7ff8fb34:
code_r0x0072ed52:
          return L"ERROR_ADDRESS_NOT_ASSOCIATED";
        case -0x7ff8fb33:
code_r0x0072ed5c:
          return L"ERROR_CONNECTION_INVALID";
        case -0x7ff8fb32:
code_r0x0072ed66:
          return L"ERROR_CONNECTION_ACTIVE";
        case -0x7ff8fb31:
code_r0x0072ed70:
          return L"ERROR_NETWORK_UNREACHABLE";
        case -0x7ff8fb30:
code_r0x0072ed7a:
          return L"ERROR_HOST_UNREACHABLE";
        case -0x7ff8fb2f:
code_r0x0072ed84:
          return L"ERROR_PROTOCOL_UNREACHABLE";
        case -0x7ff8fb2e:
code_r0x0072ed8e:
          return L"ERROR_PORT_UNREACHABLE";
        case -0x7ff8fb2d:
code_r0x0072ed98:
          return L"ERROR_REQUEST_ABORTED";
        case -0x7ff8fb2c:
code_r0x0072eda2:
          return L"ERROR_CONNECTION_ABORTED";
        case -0x7ff8fb2b:
code_r0x0072edac:
          return L"ERROR_RETRY";
        case -0x7ff8fb2a:
code_r0x0072edb6:
          return L"ERROR_CONNECTION_COUNT_LIMIT";
        case -0x7ff8fb29:
code_r0x0072edc0:
          return L"ERROR_LOGIN_TIME_RESTRICTION";
        case -0x7ff8fb28:
code_r0x0072edca:
          return L"ERROR_LOGIN_WKSTA_RESTRICTION";
        case -0x7ff8fb27:
code_r0x0072edd4:
          return L"ERROR_INCORRECT_ADDRESS";
        case -0x7ff8fb26:
code_r0x0072edde:
          return L"ERROR_ALREADY_REGISTERED";
        case -0x7ff8fb25:
code_r0x0072ede8:
          return L"ERROR_SERVICE_NOT_FOUND";
        case -0x7ff8fb24:
code_r0x0072edf2:
          return L"ERROR_NOT_AUTHENTICATED";
        case -0x7ff8fb23:
code_r0x0072edfc:
          return L"ERROR_NOT_LOGGED_ON";
        case -0x7ff8fb22:
code_r0x0072ee06:
          return L"ERROR_CONTINUE";
        case -0x7ff8fb21:
code_r0x0072ee10:
          return L"ERROR_ALREADY_INITIALIZED & DIERR_ALREADYINITIALIZED";
        case -0x7ff8fb20:
code_r0x0072ee1a:
          return L"ERROR_NO_MORE_DEVICES";
        case -0x7ff8fb1f:
code_r0x0072ee24:
          return L"ERROR_NO_SUCH_SITE";
        case -0x7ff8fb1e:
code_r0x0072ee2e:
          return L"ERROR_DOMAIN_CONTROLLER_EXISTS";
        case -0x7ff8fb1d:
code_r0x0072f464:
          return L"ERROR_ONLY_IF_CONNECTED";
        case -0x7ff8fb1c:
code_r0x0072f46e:
          return L"ERROR_OVERRIDE_NOCHANGES";
        case -0x7ff8fb1b:
code_r0x0072f478:
          return L"ERROR_BAD_USER_PROFILE";
        case -0x7ff8fb1a:
code_r0x0072f482:
          return L"ERROR_NOT_SUPPORTED_ON_SBS";
        case -0x7ff8fb19:
code_r0x0072f48c:
          return L"ERROR_SERVER_SHUTDOWN_IN_PROGRESS";
        case -0x7ff8fb18:
code_r0x0072f496:
          return L"ERROR_HOST_DOWN";
        case -0x7ff8fb17:
code_r0x0072f4a0:
          return L"ERROR_NON_ACCOUNT_SID";
        case -0x7ff8fb16:
code_r0x0072f4aa:
          return L"ERROR_NON_DOMAIN_SID";
        case -0x7ff8fb15:
code_r0x0072f4b4:
          return L"ERROR_APPHELP_BLOCK";
        case -0x7ff8fb14:
code_r0x0072f4be:
          return L"ERROR_ACCESS_DISABLED_BY_POLICY";
        case -0x7ff8fb13:
code_r0x0072f4c8:
          return L"ERROR_REG_NAT_CONSUMPTION";
        case -0x7ff8fb12:
code_r0x0072f4d2:
          return L"ERROR_CSCSHARE_OFFLINE";
        case -0x7ff8fb11:
code_r0x0072f4dc:
          return L"ERROR_PKINIT_FAILURE";
        case -0x7ff8fb10:
LAB_0072f4e6:
          return L"ERROR_SMARTCARD_SUBSYSTEM_FAILURE";
        case -0x7ff8fb0f:
code_r0x0072f4f0:
          return L"ERROR_DOWNGRADE_DETECTED";
        case -0x7ff8fb09:
code_r0x0072f4fa:
          return L"ERROR_MACHINE_LOCKED";
        case -0x7ff8fb07:
code_r0x0072f504:
          return L"ERROR_CALLBACK_SUPPLIED_INVALID_DATA";
        case -0x7ff8fb06:
code_r0x0072f50e:
          return L"ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED";
        case -0x7ff8fb05:
code_r0x0072f518:
          return L"ERROR_DRIVER_BLOCKED";
        case -0x7ff8fb04:
code_r0x0072f522:
          return L"ERROR_INVALID_IMPORT_OF_NON_DLL";
        case -0x7ff8faec:
code_r0x0072ee38:
          return L"ERROR_NOT_ALL_ASSIGNED";
        case -0x7ff8faeb:
code_r0x0072ee42:
          return L"ERROR_SOME_NOT_MAPPED";
        case -0x7ff8faea:
code_r0x0072ee4c:
          return L"ERROR_NO_QUOTAS_FOR_ACCOUNT";
        case -0x7ff8fae9:
code_r0x0072ee56:
          return L"ERROR_LOCAL_USER_SESSION_KEY";
        case -0x7ff8fae8:
code_r0x0072ee60:
          return L"ERROR_NULL_LM_PASSWORD";
        case -0x7ff8fae7:
code_r0x0072ee6a:
          return L"ERROR_UNKNOWN_REVISION";
        case -0x7ff8fae6:
code_r0x0072ee74:
          return L"ERROR_REVISION_MISMATCH";
        case -0x7ff8fae5:
code_r0x0072ee7e:
          return L"ERROR_INVALID_OWNER";
        case -0x7ff8fae4:
code_r0x0072ee88:
          return L"ERROR_INVALID_PRIMARY_GROUP";
        case -0x7ff8fae3:
code_r0x0072ee92:
          return L"ERROR_NO_IMPERSONATION_TOKEN";
        case -0x7ff8fae2:
code_r0x0072ee9c:
          return L"ERROR_CANT_DISABLE_MANDATORY";
        case -0x7ff8fae1:
code_r0x0072eea6:
          return L"ERROR_NO_LOGON_SERVERS";
        case -0x7ff8fae0:
code_r0x0072eeb0:
          return L"ERROR_NO_SUCH_LOGON_SESSION";
        case -0x7ff8fadf:
code_r0x0072eeba:
          return L"ERROR_NO_SUCH_PRIVILEGE";
        case -0x7ff8fade:
code_r0x0072eec4:
          return L"ERROR_PRIVILEGE_NOT_HELD";
        case -0x7ff8fadd:
code_r0x0072eece:
          return L"ERROR_INVALID_ACCOUNT_NAME";
        case -0x7ff8fadc:
code_r0x0072eed8:
          return L"ERROR_USER_EXISTS";
        case -0x7ff8fadb:
code_r0x0072eee2:
          return L"ERROR_NO_SUCH_USER";
        case -0x7ff8fada:
code_r0x0072eeec:
          return L"ERROR_GROUP_EXISTS";
        case -0x7ff8fad9:
code_r0x0072eef6:
          return L"ERROR_NO_SUCH_GROUP";
        case -0x7ff8fad8:
code_r0x0072ef00:
          return L"ERROR_MEMBER_IN_GROUP";
        case -0x7ff8fad7:
code_r0x0072ef0a:
          return L"ERROR_MEMBER_NOT_IN_GROUP";
        case -0x7ff8fad6:
code_r0x0072ef14:
          return L"ERROR_LAST_ADMIN";
        case -0x7ff8fad5:
code_r0x0072ef1e:
          return L"ERROR_WRONG_PASSWORD";
        case -0x7ff8fad4:
code_r0x0072ef28:
          return L"ERROR_ILL_FORMED_PASSWORD";
        case -0x7ff8fad3:
code_r0x0072ef32:
          return L"ERROR_PASSWORD_RESTRICTION";
        case -0x7ff8fad2:
code_r0x0072ef3c:
          return L"ERROR_LOGON_FAILURE";
        case -0x7ff8fad1:
code_r0x0072ef46:
          return L"ERROR_ACCOUNT_RESTRICTION";
        case -0x7ff8fad0:
code_r0x0072ef50:
          return L"ERROR_INVALID_LOGON_HOURS";
        case -0x7ff8facf:
code_r0x0072ef5a:
          return L"ERROR_INVALID_WORKSTATION";
        case -0x7ff8face:
code_r0x0072ef64:
          return L"ERROR_PASSWORD_EXPIRED";
        case -0x7ff8facd:
code_r0x0072ef6e:
          return L"ERROR_ACCOUNT_DISABLED";
        case -0x7ff8facc:
code_r0x0072ef78:
          return L"ERROR_NONE_MAPPED";
        case -0x7ff8facb:
code_r0x0072ef82:
          return L"ERROR_TOO_MANY_LUIDS_REQUESTED";
        case -0x7ff8faca:
code_r0x0072ef8c:
          return L"ERROR_LUIDS_EXHAUSTED";
        case -0x7ff8fac9:
code_r0x0072ef96:
          return L"ERROR_INVALID_SUB_AUTHORITY";
        case -0x7ff8fac8:
code_r0x0072efa0:
          return L"ERROR_INVALID_ACL";
        case -0x7ff8fac7:
code_r0x0072efaa:
          return L"ERROR_INVALID_SID";
        case -0x7ff8fac6:
code_r0x0072efb4:
          return L"ERROR_INVALID_SECURITY_DESCR";
        case -0x7ff8fac4:
code_r0x0072efbe:
          return L"ERROR_BAD_INHERITANCE_ACL";
        case -0x7ff8fac3:
code_r0x0072efc8:
          return L"ERROR_SERVER_DISABLED";
        case -0x7ff8fac2:
code_r0x0072efd2:
          return L"ERROR_SERVER_NOT_DISABLED";
        case -0x7ff8fac1:
code_r0x0072efdc:
          return L"ERROR_INVALID_ID_AUTHORITY";
        case -0x7ff8fac0:
code_r0x0072efe6:
          return L"ERROR_ALLOTTED_SPACE_EXCEEDED";
        case -0x7ff8fabf:
code_r0x0072eff0:
          return L"ERROR_INVALID_GROUP_ATTRIBUTES";
        case -0x7ff8fabe:
code_r0x0072effa:
          return L"ERROR_BAD_IMPERSONATION_LEVEL";
        case -0x7ff8fabd:
code_r0x0072f004:
          return L"ERROR_CANT_OPEN_ANONYMOUS";
        case -0x7ff8fabc:
code_r0x0072f00e:
          return L"ERROR_BAD_VALIDATION_CLASS";
        case -0x7ff8fabb:
code_r0x0072f018:
          return L"ERROR_BAD_TOKEN_TYPE";
        case -0x7ff8faba:
code_r0x0072f022:
          return L"ERROR_NO_SECURITY_ON_OBJECT";
        case -0x7ff8fab9:
code_r0x0072f02c:
          return L"ERROR_CANT_ACCESS_DOMAIN_INFO";
        case -0x7ff8fab8:
code_r0x0072f036:
          return L"ERROR_INVALID_SERVER_STATE";
        case -0x7ff8fab7:
code_r0x0072f040:
          return L"ERROR_INVALID_DOMAIN_STATE";
        case -0x7ff8fab6:
code_r0x0072f04a:
          return L"ERROR_INVALID_DOMAIN_ROLE";
        case -0x7ff8fab5:
code_r0x0072f054:
          return L"ERROR_NO_SUCH_DOMAIN";
        case -0x7ff8fab4:
code_r0x0072f05e:
          return L"ERROR_DOMAIN_EXISTS";
        case -0x7ff8fab3:
code_r0x0072f068:
          return L"ERROR_DOMAIN_LIMIT_EXCEEDED";
        case -0x7ff8fab2:
code_r0x0072f072:
          return L"ERROR_INTERNAL_DB_CORRUPTION";
        case -0x7ff8fab1:
code_r0x0072f07c:
          return L"ERROR_INTERNAL_ERROR";
        case -0x7ff8fab0:
code_r0x0072f086:
          return L"ERROR_GENERIC_NOT_MAPPED";
        case -0x7ff8faaf:
code_r0x0072f090:
          return L"ERROR_BAD_DESCRIPTOR_FORMAT";
        case -0x7ff8faae:
code_r0x0072f09a:
          return L"ERROR_NOT_LOGON_PROCESS";
        case -0x7ff8faad:
code_r0x0072f0a4:
          return L"ERROR_LOGON_SESSION_EXISTS";
        case -0x7ff8faac:
code_r0x0072f0ae:
          return L"ERROR_NO_SUCH_PACKAGE";
        case -0x7ff8faab:
code_r0x0072f0b8:
          return L"ERROR_BAD_LOGON_SESSION_STATE";
        case -0x7ff8faaa:
code_r0x0072f0c2:
          return L"ERROR_LOGON_SESSION_COLLISION";
        case -0x7ff8faa9:
code_r0x0072f0cc:
          return L"ERROR_INVALID_LOGON_TYPE";
        case -0x7ff8faa8:
code_r0x0072f0d6:
          return L"ERROR_CANNOT_IMPERSONATE";
        case -0x7ff8faa7:
code_r0x0072f0e0:
          return L"ERROR_RXACT_INVALID_STATE";
        case -0x7ff8faa6:
code_r0x0072f0ea:
          return L"ERROR_RXACT_COMMIT_FAILURE";
        case -0x7ff8faa5:
code_r0x0072f0f4:
          return L"ERROR_SPECIAL_ACCOUNT";
        case -0x7ff8faa4:
code_r0x0072f0fe:
          return L"ERROR_SPECIAL_GROUP";
        case -0x7ff8faa3:
code_r0x0072f108:
          return L"ERROR_SPECIAL_USER";
        case -0x7ff8faa2:
code_r0x0072f112:
          return L"ERROR_MEMBERS_PRIMARY_GROUP";
        case -0x7ff8faa1:
code_r0x0072f11c:
          return L"ERROR_TOKEN_ALREADY_IN_USE";
        case -0x7ff8faa0:
code_r0x0072f126:
          return L"ERROR_NO_SUCH_ALIAS";
        case -0x7ff8fa9f:
code_r0x0072f130:
          return L"ERROR_MEMBER_NOT_IN_ALIAS";
        case -0x7ff8fa9e:
code_r0x0072f13a:
          return L"ERROR_MEMBER_IN_ALIAS";
        case -0x7ff8fa9d:
code_r0x0072f144:
          return L"ERROR_ALIAS_EXISTS";
        case -0x7ff8fa9c:
code_r0x0072f14e:
          return L"ERROR_LOGON_NOT_GRANTED";
        case -0x7ff8fa9b:
code_r0x0072f158:
          return L"ERROR_TOO_MANY_SECRETS";
        case -0x7ff8fa9a:
code_r0x0072f162:
          return L"ERROR_SECRET_TOO_LONG";
        case -0x7ff8fa99:
code_r0x0072f16c:
          return L"ERROR_INTERNAL_DB_ERROR";
        case -0x7ff8fa98:
code_r0x0072f176:
          return L"ERROR_TOO_MANY_CONTEXT_IDS";
        case -0x7ff8fa97:
code_r0x0072f180:
          return L"ERROR_LOGON_TYPE_NOT_GRANTED";
        case -0x7ff8fa96:
code_r0x0072f18a:
          return L"ERROR_NT_CROSS_ENCRYPTION_REQUIRED";
        case -0x7ff8fa95:
code_r0x0072f194:
          return L"ERROR_NO_SUCH_MEMBER";
        case -0x7ff8fa94:
code_r0x0072f19e:
          return L"ERROR_INVALID_MEMBER";
        case -0x7ff8fa93:
code_r0x0072f1a8:
          return L"ERROR_TOO_MANY_SIDS";
        case -0x7ff8fa92:
code_r0x0072f1b2:
          return L"ERROR_LM_CROSS_ENCRYPTION_REQUIRED";
        case -0x7ff8fa91:
code_r0x0072f1bc:
          return L"ERROR_NO_INHERITANCE";
        case -0x7ff8fa90:
code_r0x0072f1c6:
          return L"ERROR_FILE_CORRUPT";
        case -0x7ff8fa8f:
code_r0x0072f1d0:
          return L"ERROR_DISK_CORRUPT";
        case -0x7ff8fa8e:
code_r0x0072f1da:
          return L"ERROR_NO_USER_SESSION_KEY";
        case -0x7ff8fa8d:
code_r0x0072f1e4:
          return L"ERROR_LICENSE_QUOTA_EXCEEDED";
        case -0x7ff8fa8c:
code_r0x0072f1ee:
          return L"ERROR_WRONG_TARGET_NAME";
        case -0x7ff8fa8b:
code_r0x0072f1f8:
          return L"ERROR_MUTUAL_AUTH_FAILED";
        case -0x7ff8fa8a:
code_r0x0072f202:
          return L"ERROR_TIME_SKEW";
        case -0x7ff8fa89:
code_r0x0072f52c:
          return L"ERROR_CURRENT_DOMAIN_NOT_ALLOWED";
        case -0x7ff8fa88:
code_r0x0072f20c:
          return L"ERROR_INVALID_WINDOW_HANDLE";
        case -0x7ff8fa87:
code_r0x0072f216:
          return L"ERROR_INVALID_MENU_HANDLE";
        case -0x7ff8fa86:
code_r0x0072f220:
          return L"ERROR_INVALID_CURSOR_HANDLE";
        case -0x7ff8fa85:
code_r0x0072f22a:
          return L"ERROR_INVALID_ACCEL_HANDLE";
        case -0x7ff8fa84:
code_r0x0072f234:
          return L"ERROR_INVALID_HOOK_HANDLE";
        case -0x7ff8fa83:
code_r0x0072f23e:
          return L"ERROR_INVALID_DWP_HANDLE";
        case -0x7ff8fa82:
code_r0x0072f248:
          return L"ERROR_TLW_WITH_WSCHILD";
        case -0x7ff8fa81:
code_r0x0072f252:
          return L"ERROR_CANNOT_FIND_WND_CLASS";
        case -0x7ff8fa80:
code_r0x0072f25c:
          return L"ERROR_WINDOW_OF_OTHER_THREAD";
        case -0x7ff8fa7f:
code_r0x0072f266:
          return L"ERROR_HOTKEY_ALREADY_REGISTERED";
        case -0x7ff8fa7e:
code_r0x0072f270:
          return L"ERROR_CLASS_ALREADY_EXISTS";
        case -0x7ff8fa7d:
code_r0x0072f27a:
          return L"ERROR_CLASS_DOES_NOT_EXIST";
        case -0x7ff8fa7c:
code_r0x0072f284:
          return L"ERROR_CLASS_HAS_WINDOWS";
        case -0x7ff8fa7b:
code_r0x0072f28e:
          return L"ERROR_INVALID_INDEX";
        case -0x7ff8fa7a:
code_r0x0072f298:
          return L"ERROR_INVALID_ICON_HANDLE";
        case -0x7ff8fa79:
code_r0x0072f2a2:
          return L"ERROR_PRIVATE_DIALOG_INDEX";
        case -0x7ff8fa78:
code_r0x0072f2ac:
          return L"ERROR_LISTBOX_ID_NOT_FOUND";
        case -0x7ff8fa77:
code_r0x0072f2b6:
          return L"ERROR_NO_WILDCARD_CHARACTERS";
        case -0x7ff8fa76:
code_r0x0072f2c0:
          return L"ERROR_CLIPBOARD_NOT_OPEN";
        case -0x7ff8fa75:
code_r0x0072f2ca:
          return L"ERROR_HOTKEY_NOT_REGISTERED";
        case -0x7ff8fa74:
code_r0x0072f2d4:
          return L"ERROR_WINDOW_NOT_DIALOG";
        case -0x7ff8fa73:
code_r0x0072f2de:
          return L"ERROR_CONTROL_ID_NOT_FOUND";
        case -0x7ff8fa72:
code_r0x0072f2e8:
          return L"ERROR_INVALID_COMBOBOX_MESSAGE";
        case -0x7ff8fa71:
code_r0x0072f2f2:
          return L"ERROR_WINDOW_NOT_COMBOBOX";
        case -0x7ff8fa70:
code_r0x0072f2fc:
          return L"ERROR_INVALID_EDIT_HEIGHT";
        case -0x7ff8fa6f:
code_r0x0072f306:
          return L"ERROR_DC_NOT_FOUND";
        case -0x7ff8fa6e:
code_r0x0072f310:
          return L"ERROR_INVALID_HOOK_FILTER";
        case -0x7ff8fa6d:
code_r0x0072f31a:
          return L"ERROR_INVALID_FILTER_PROC";
        case -0x7ff8fa6c:
code_r0x0072f324:
          return L"ERROR_HOOK_NEEDS_HMOD";
        case -0x7ff8fa6b:
code_r0x0072f32e:
          return L"ERROR_GLOBAL_ONLY_HOOK";
        case -0x7ff8fa6a:
code_r0x0072f338:
          return L"ERROR_JOURNAL_HOOK_SET";
        case -0x7ff8fa69:
code_r0x0072f342:
          return L"ERROR_HOOK_NOT_INSTALLED";
        case -0x7ff8fa68:
code_r0x0072f34c:
          return L"ERROR_INVALID_LB_MESSAGE";
        case -0x7ff8fa67:
code_r0x0072f356:
          return L"ERROR_SETCOUNT_ON_BAD_LB";
        case -0x7ff8fa66:
code_r0x0072f360:
          return L"ERROR_LB_WITHOUT_TABSTOPS";
        case -0x7ff8fa65:
code_r0x0072f36a:
          return L"ERROR_DESTROY_OBJECT_OF_OTHER_THREAD";
        case -0x7ff8fa64:
code_r0x0072f374:
          return L"ERROR_CHILD_WINDOW_MENU";
        case -0x7ff8fa63:
code_r0x0072f37e:
          return L"ERROR_NO_SYSTEM_MENU";
        case -0x7ff8fa62:
code_r0x0072f388:
          return L"ERROR_INVALID_MSGBOX_STYLE";
        case -0x7ff8fa61:
code_r0x0072f392:
          return L"ERROR_INVALID_SPI_VALUE";
        case -0x7ff8fa60:
code_r0x0072f39c:
          return L"ERROR_SCREEN_ALREADY_LOCKED";
        case -0x7ff8fa5f:
code_r0x0072f3a6:
          return L"ERROR_HWNDS_HAVE_DIFF_PARENT";
        case -0x7ff8fa5e:
code_r0x0072f3b0:
          return L"ERROR_NOT_CHILD_WINDOW";
        case -0x7ff8fa5d:
code_r0x0072f3ba:
          return L"ERROR_INVALID_GW_COMMAND";
        case -0x7ff8fa5c:
code_r0x0072f3c4:
          return L"ERROR_INVALID_THREAD_ID";
        case -0x7ff8fa5b:
code_r0x0072f3ce:
          return L"ERROR_NON_MDICHILD_WINDOW";
        case -0x7ff8fa5a:
code_r0x0072f3d8:
          return L"ERROR_POPUP_ALREADY_ACTIVE";
        case -0x7ff8fa59:
code_r0x0072f3e2:
          return L"ERROR_NO_SCROLLBARS";
        case -0x7ff8fa58:
code_r0x0072f3ec:
          return L"ERROR_INVALID_SCROLLBAR_RANGE";
        case -0x7ff8fa57:
code_r0x0072f3f6:
          return L"ERROR_INVALID_SHOWWIN_COMMAND";
        case -0x7ff8fa56:
code_r0x0072f400:
          return L"ERROR_NO_SYSTEM_RESOURCES";
        case -0x7ff8fa55:
code_r0x0072f40a:
          return L"ERROR_NONPAGED_SYSTEM_RESOURCES";
        case -0x7ff8fa54:
code_r0x0072f414:
          return L"ERROR_PAGED_SYSTEM_RESOURCES";
        case -0x7ff8fa53:
code_r0x0072f41e:
          return L"ERROR_WORKING_SET_QUOTA";
        case -0x7ff8fa52:
code_r0x0072f428:
          return L"ERROR_PAGEFILE_QUOTA";
        case -0x7ff8fa51:
code_r0x0072f432:
          return L"ERROR_COMMITMENT_LIMIT";
        case -0x7ff8fa50:
code_r0x0072f43c:
          return L"ERROR_MENU_ITEM_NOT_FOUND";
        case -0x7ff8fa4f:
code_r0x0072f446:
          return L"ERROR_INVALID_KEYBOARD_HANDLE";
        case -0x7ff8fa4e:
code_r0x0072f450:
          return L"ERROR_HOOK_TYPE_NOT_ALLOWED";
        case -0x7ff8fa4d:
          goto LAB_0072f536;
        case -0x7ff8fa4c:
code_r0x0072f597:
          return L"ERROR_TIMEOUT";
        case -0x7ff8fa4b:
code_r0x0072f5a1:
          return L"ERROR_INVALID_MONITOR_HANDLE";
        case -0x7ff8fa24:
code_r0x0072f5ab:
          return L"ERROR_EVENTLOG_FILE_CORRUPT";
        case -0x7ff8fa23:
code_r0x0072f5b5:
          return L"ERROR_EVENTLOG_CANT_START";
        case -0x7ff8fa22:
code_r0x0072f5bf:
          return L"ERROR_LOG_FILE_FULL";
        case -0x7ff8fa21:
code_r0x0072f5c9:
          return L"ERROR_EVENTLOG_FILE_CHANGED";
        case -0x7ff8f9bf:
code_r0x0072fb0f:
          return L"ERROR_INSTALL_SERVICE_FAILURE";
        case -0x7ff8f9be:
code_r0x0072f5d3:
          return L"ERROR_INSTALL_USEREXIT";
        case -0x7ff8f9bd:
code_r0x0072f5dd:
          return L"ERROR_INSTALL_FAILURE";
        case -0x7ff8f9bc:
code_r0x0072f5e7:
          return L"ERROR_INSTALL_SUSPEND";
        case -0x7ff8f9bb:
code_r0x0072f5f1:
          return L"ERROR_UNKNOWN_PRODUCT";
        case -0x7ff8f9ba:
code_r0x0072f5fb:
          return L"ERROR_UNKNOWN_FEATURE";
        case -0x7ff8f9b9:
code_r0x0072f605:
          return L"ERROR_UNKNOWN_COMPONENT";
        case -0x7ff8f9b8:
code_r0x0072f60f:
          return L"ERROR_UNKNOWN_PROPERTY";
        case -0x7ff8f9b7:
code_r0x0072f619:
          return L"ERROR_INVALID_HANDLE_STATE";
        case -0x7ff8f9b6:
code_r0x0072f623:
          return L"ERROR_BAD_CONFIGURATION";
        case -0x7ff8f9b5:
code_r0x0072f62d:
          return L"ERROR_INDEX_ABSENT";
        case -0x7ff8f9b4:
code_r0x0072f637:
          return L"ERROR_INSTALL_SOURCE_ABSENT";
        case -0x7ff8f9b3:
code_r0x0072fb19:
          return L"ERROR_INSTALL_PACKAGE_VERSION";
        case -0x7ff8f9b2:
code_r0x0072f641:
          return L"ERROR_PRODUCT_UNINSTALLED";
        case -0x7ff8f9b1:
code_r0x0072f64b:
          return L"ERROR_BAD_QUERY_SYNTAX";
        case -0x7ff8f9b0:
code_r0x0072f655:
          return L"ERROR_INVALID_FIELD";
        case -0x7ff8f9af:
code_r0x0072f65f:
          return L"ERROR_DEVICE_REMOVED";
        case -0x7ff8f9ae:
code_r0x0072fb23:
          return L"ERROR_INSTALL_ALREADY_RUNNING";
        case -0x7ff8f9ad:
code_r0x0072fb2d:
          return L"ERROR_INSTALL_PACKAGE_OPEN_FAILED";
        case -0x7ff8f9ac:
code_r0x0072fb37:
          return L"ERROR_INSTALL_PACKAGE_INVALID";
        case -0x7ff8f9ab:
code_r0x0072fb41:
          return L"ERROR_INSTALL_UI_FAILURE";
        case -0x7ff8f9aa:
code_r0x0072fb4b:
          return L"ERROR_INSTALL_LOG_FAILURE";
        case -0x7ff8f9a9:
code_r0x0072fb55:
          return L"ERROR_INSTALL_LANGUAGE_UNSUPPORTED";
        case -0x7ff8f9a8:
code_r0x0072fb5f:
          return L"ERROR_INSTALL_TRANSFORM_FAILURE";
        case -0x7ff8f9a7:
code_r0x0072fb69:
          return L"ERROR_INSTALL_PACKAGE_REJECTED";
        case -0x7ff8f9a6:
code_r0x0072fb73:
          return L"ERROR_FUNCTION_NOT_CALLED";
        case -0x7ff8f9a5:
code_r0x0072fb7d:
          return L"ERROR_FUNCTION_FAILED";
        case -0x7ff8f9a4:
code_r0x0072fb87:
          return L"ERROR_INVALID_TABLE";
        case -0x7ff8f9a3:
code_r0x0072fb91:
          return L"ERROR_DATATYPE_MISMATCH";
        case -0x7ff8f9a2:
code_r0x0072fb9b:
          return L"ERROR_UNSUPPORTED_TYPE";
        case -0x7ff8f9a1:
code_r0x0072fba5:
          return L"ERROR_CREATE_FAILED";
        case -0x7ff8f9a0:
code_r0x0072fbaf:
          return L"ERROR_INSTALL_TEMP_UNWRITABLE";
        case -0x7ff8f99f:
code_r0x0072fbb9:
          return L"ERROR_INSTALL_PLATFORM_UNSUPPORTED";
        case -0x7ff8f99e:
code_r0x0072fbc3:
          return L"ERROR_INSTALL_NOTUSED";
        case -0x7ff8f99d:
code_r0x0072fbcd:
          return L"ERROR_PATCH_PACKAGE_OPEN_FAILED";
        case -0x7ff8f99c:
code_r0x0072fbd7:
          return L"ERROR_PATCH_PACKAGE_INVALID";
        case -0x7ff8f99b:
code_r0x0072fbe1:
          return L"ERROR_PATCH_PACKAGE_UNSUPPORTED";
        case -0x7ff8f99a:
code_r0x0072fbeb:
          return L"ERROR_PRODUCT_VERSION";
        case -0x7ff8f999:
code_r0x0072fbf5:
          return L"ERROR_INVALID_COMMAND_LINE";
        case -0x7ff8f998:
code_r0x0072fbff:
          return L"ERROR_INSTALL_REMOTE_DISALLOWED";
        case -0x7ff8f997:
code_r0x0072fc09:
          return L"ERROR_SUCCESS_REBOOT_INITIATED";
        case -0x7ff8f996:
code_r0x0072fc13:
          return L"ERROR_PATCH_TARGET_NOT_FOUND";
        case -0x7ff8f995:
code_r0x0072fc1d:
          return L"ERROR_PATCH_PACKAGE_REJECTED";
        case -0x7ff8f994:
code_r0x0072fc27:
          return L"ERROR_INSTALL_TRANSFORM_REJECTED";
        case -0x7ff8f95c:
code_r0x0072f669:
          return L"RPC_S_INVALID_STRING_BINDING";
        case -0x7ff8f95b:
code_r0x0072f673:
          return L"RPC_S_WRONG_KIND_OF_BINDING";
        case -0x7ff8f95a:
code_r0x0072f67d:
          return L"RPC_S_INVALID_BINDING";
        case -0x7ff8f959:
code_r0x0072f687:
          return L"RPC_S_PROTSEQ_NOT_SUPPORTED";
        case -0x7ff8f958:
code_r0x0072f691:
          return L"RPC_S_INVALID_RPC_PROTSEQ";
        case -0x7ff8f957:
code_r0x0072f69b:
          return L"RPC_S_INVALID_STRING_UUID";
        case -0x7ff8f956:
code_r0x0072f6a5:
          return L"RPC_S_INVALID_ENDPOINT_FORMAT";
        case -0x7ff8f955:
code_r0x0072f6af:
          return L"RPC_S_INVALID_NET_ADDR";
        case -0x7ff8f954:
code_r0x0072f6b9:
          return L"RPC_S_NO_ENDPOINT_FOUND";
        case -0x7ff8f953:
code_r0x0072f6c3:
          return L"RPC_S_INVALID_TIMEOUT";
        case -0x7ff8f952:
code_r0x0072f6cd:
          return L"RPC_S_OBJECT_NOT_FOUND";
        case -0x7ff8f951:
code_r0x0072f6d7:
          return L"RPC_S_ALREADY_REGISTERED";
        case -0x7ff8f950:
code_r0x0072f6e1:
          return L"RPC_S_TYPE_ALREADY_REGISTERED";
        case -0x7ff8f94f:
code_r0x0072f6eb:
          return L"RPC_S_ALREADY_LISTENING";
        case -0x7ff8f94e:
code_r0x0072f6f5:
          return L"RPC_S_NO_PROTSEQS_REGISTERED";
        case -0x7ff8f94d:
code_r0x0072f6ff:
          return L"RPC_S_NOT_LISTENING";
        case -0x7ff8f94c:
code_r0x0072f709:
          return L"RPC_S_UNKNOWN_MGR_TYPE";
        case -0x7ff8f94b:
code_r0x0072f713:
          return L"RPC_S_UNKNOWN_IF";
        }
      }
    }
    else if (param_1 < -0x7ff8f735) {
      if (param_1 == -0x7ff8f736) {
LAB_0072ffa8:
        return L"ERROR_NOT_CONNECTED";
      }
      if (param_1 + 0x7ff8f949U < 0x1e4) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
        switch(*(undefined1 *)(param_1 + -0x7f93b66d)) {
        case 0:
code_r0x0072f727:
          return L"RPC_S_NO_PROTSEQS";
        case 1:
code_r0x0072f731:
          return L"RPC_S_CANT_CREATE_ENDPOINT";
        case 2:
code_r0x0072f73b:
          return L"RPC_S_OUT_OF_RESOURCES";
        case 3:
code_r0x0072f745:
          return L"RPC_S_SERVER_UNAVAILABLE";
        case 4:
code_r0x0072f74f:
          return L"RPC_S_SERVER_TOO_BUSY";
        case 5:
code_r0x0072f759:
          return L"RPC_S_INVALID_NETWORK_OPTIONS";
        case 6:
code_r0x0072f763:
          return L"RPC_S_NO_CALL_ACTIVE";
        case 7:
code_r0x0072f76d:
          return L"RPC_S_CALL_FAILED";
        case 8:
code_r0x0072f777:
          return L"RPC_S_CALL_FAILED_DNE";
        case 9:
code_r0x0072f781:
          return L"RPC_S_PROTOCOL_ERROR";
        case 10:
code_r0x0072f78b:
          return L"RPC_S_UNSUPPORTED_TRANS_SYN";
        case 0xb:
code_r0x0072f795:
          return L"RPC_S_UNSUPPORTED_TYPE";
        case 0xc:
code_r0x0072f79f:
          return L"RPC_S_INVALID_TAG";
        case 0xd:
code_r0x0072f7a9:
          return L"RPC_S_INVALID_BOUND";
        case 0xe:
code_r0x0072f7b3:
          return L"RPC_S_NO_ENTRY_NAME";
        case 0xf:
code_r0x0072f7bd:
          return L"RPC_S_INVALID_NAME_SYNTAX";
        case 0x10:
code_r0x0072f7c7:
          return L"RPC_S_UNSUPPORTED_NAME_SYNTAX";
        case 0x11:
code_r0x0072f7d1:
          return L"RPC_S_UUID_NO_ADDRESS";
        case 0x12:
code_r0x0072f7db:
          return L"RPC_S_DUPLICATE_ENDPOINT";
        case 0x13:
code_r0x0072f7e5:
          return L"RPC_S_UNKNOWN_AUTHN_TYPE";
        case 0x14:
code_r0x0072f7ef:
          return L"RPC_S_MAX_CALLS_TOO_SMALL";
        case 0x15:
code_r0x0072f7f9:
          return L"RPC_S_STRING_TOO_LONG";
        case 0x16:
code_r0x0072f803:
          return L"RPC_S_PROTSEQ_NOT_FOUND";
        case 0x17:
code_r0x0072f80d:
          return L"RPC_S_PROCNUM_OUT_OF_RANGE";
        case 0x18:
code_r0x0072f817:
          return L"RPC_S_BINDING_HAS_NO_AUTH";
        case 0x19:
code_r0x0072f821:
          return L"RPC_S_UNKNOWN_AUTHN_SERVICE";
        case 0x1a:
code_r0x0072f82b:
          return L"RPC_S_UNKNOWN_AUTHN_LEVEL";
        case 0x1b:
code_r0x0072f835:
          return L"RPC_S_INVALID_AUTH_IDENTITY";
        case 0x1c:
code_r0x0072f83f:
          return L"RPC_S_UNKNOWN_AUTHZ_SERVICE";
        case 0x1d:
code_r0x0072f849:
          return L"EPT_S_INVALID_ENTRY";
        case 0x1e:
code_r0x0072f853:
          return L"EPT_S_CANT_PERFORM_OP";
        case 0x1f:
code_r0x0072f85d:
          return L"EPT_S_NOT_REGISTERED";
        case 0x20:
code_r0x0072f867:
          return L"RPC_S_NOTHING_TO_EXPORT";
        case 0x21:
code_r0x0072f871:
          return L"RPC_S_INCOMPLETE_NAME";
        case 0x22:
code_r0x0072f87b:
          return L"RPC_S_INVALID_VERS_OPTION";
        case 0x23:
code_r0x0072f885:
          return L"RPC_S_NO_MORE_MEMBERS";
        case 0x24:
code_r0x0072f88f:
          return L"RPC_S_NOT_ALL_OBJS_UNEXPORTED";
        case 0x25:
code_r0x0072f899:
          return L"RPC_S_INTERFACE_NOT_FOUND";
        case 0x26:
code_r0x0072f8a3:
          return L"RPC_S_ENTRY_ALREADY_EXISTS";
        case 0x27:
code_r0x0072f8ad:
          return L"RPC_S_ENTRY_NOT_FOUND";
        case 0x28:
code_r0x0072f8b7:
          return L"RPC_S_NAME_SERVICE_UNAVAILABLE";
        case 0x29:
code_r0x0072f8c1:
          return L"RPC_S_INVALID_NAF_ID";
        case 0x2a:
code_r0x0072f8cb:
          return L"RPC_S_CANNOT_SUPPORT";
        case 0x2b:
code_r0x0072f8d5:
          return L"RPC_S_NO_CONTEXT_AVAILABLE";
        case 0x2c:
code_r0x0072f8df:
          return L"RPC_S_INTERNAL_ERROR";
        case 0x2d:
code_r0x0072f8e9:
          return L"RPC_S_ZERO_DIVIDE";
        case 0x2e:
code_r0x0072f8f3:
          return L"RPC_S_ADDRESS_ERROR";
        case 0x2f:
code_r0x0072f8fd:
          return L"RPC_S_FP_DIV_ZERO";
        case 0x30:
code_r0x0072f907:
          return L"RPC_S_FP_UNDERFLOW";
        case 0x31:
code_r0x0072f911:
          return L"RPC_S_FP_OVERFLOW";
        case 0x32:
code_r0x0072f91b:
          return L"RPC_X_NO_MORE_ENTRIES";
        case 0x33:
code_r0x0072f925:
          return L"RPC_X_SS_CHAR_TRANS_OPEN_FAIL";
        case 0x34:
code_r0x0072f92f:
          return L"RPC_X_SS_CHAR_TRANS_SHORT_FILE";
        case 0x35:
code_r0x0072f939:
          return L"RPC_X_SS_IN_NULL_CONTEXT";
        case 0x36:
code_r0x0072f943:
          return L"RPC_X_SS_CONTEXT_DAMAGED";
        case 0x37:
code_r0x0072f94d:
          return L"RPC_X_SS_HANDLES_MISMATCH";
        case 0x38:
code_r0x0072f957:
          return L"RPC_X_SS_CANNOT_GET_CALL_HANDLE";
        case 0x39:
code_r0x0072f961:
          return L"RPC_X_NULL_REF_POINTER";
        case 0x3a:
code_r0x0072f96b:
          return L"RPC_X_ENUM_VALUE_OUT_OF_RANGE";
        case 0x3b:
code_r0x0072f975:
          return L"RPC_X_BYTE_COUNT_TOO_SMALL";
        case 0x3c:
code_r0x0072f97f:
          return L"RPC_X_BAD_STUB_DATA";
        case 0x3d:
code_r0x0072f989:
          return L"ERROR_INVALID_USER_BUFFER";
        case 0x3e:
code_r0x0072f993:
          return L"ERROR_UNRECOGNIZED_MEDIA";
        case 0x3f:
code_r0x0072f99d:
          return L"ERROR_NO_TRUST_LSA_SECRET";
        case 0x40:
code_r0x0072f9a7:
          return L"ERROR_NO_TRUST_SAM_ACCOUNT";
        case 0x41:
code_r0x0072f9b1:
          return L"ERROR_TRUSTED_DOMAIN_FAILURE";
        case 0x42:
code_r0x0072f9bb:
          return L"ERROR_TRUSTED_RELATIONSHIP_FAILURE";
        case 0x43:
code_r0x0072f9c5:
          return L"ERROR_TRUST_FAILURE";
        case 0x44:
code_r0x0072f9cf:
          return L"RPC_S_CALL_IN_PROGRESS";
        case 0x45:
code_r0x0072f9d9:
          return L"ERROR_NETLOGON_NOT_STARTED";
        case 0x46:
code_r0x0072f9e3:
          return L"ERROR_ACCOUNT_EXPIRED";
        case 0x47:
code_r0x0072f9ed:
          return L"ERROR_REDIRECTOR_HAS_OPEN_HANDLES";
        case 0x48:
code_r0x0072f9f7:
          return L"ERROR_PRINTER_DRIVER_ALREADY_INSTALLED";
        case 0x49:
code_r0x0072fa01:
          return L"ERROR_UNKNOWN_PORT";
        case 0x4a:
code_r0x0072fa0b:
          return L"ERROR_UNKNOWN_PRINTER_DRIVER";
        case 0x4b:
code_r0x0072fa15:
          return L"ERROR_UNKNOWN_PRINTPROCESSOR";
        case 0x4c:
code_r0x0072fa1f:
          return L"ERROR_INVALID_SEPARATOR_FILE";
        case 0x4d:
code_r0x0072fa29:
          return L"ERROR_INVALID_PRIORITY";
        case 0x4e:
code_r0x0072fa33:
          return L"ERROR_INVALID_PRINTER_NAME";
        case 0x4f:
code_r0x0072fa3d:
          return L"ERROR_PRINTER_ALREADY_EXISTS";
        case 0x50:
code_r0x0072fa47:
          return L"ERROR_INVALID_PRINTER_COMMAND";
        case 0x51:
code_r0x0072fa51:
          return L"ERROR_INVALID_DATATYPE";
        case 0x52:
code_r0x0072fa5b:
          return L"ERROR_INVALID_ENVIRONMENT";
        case 0x53:
code_r0x0072fa65:
          return L"RPC_S_NO_MORE_BINDINGS";
        case 0x54:
code_r0x0072fa6f:
          return L"ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT";
        case 0x55:
code_r0x0072fa79:
          return L"ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT";
        case 0x56:
code_r0x0072fa83:
          return L"ERROR_NOLOGON_SERVER_TRUST_ACCOUNT";
        case 0x57:
code_r0x0072fa8d:
          return L"ERROR_DOMAIN_TRUST_INCONSISTENT";
        case 0x58:
code_r0x0072fa97:
          return L"ERROR_SERVER_HAS_OPEN_HANDLES";
        case 0x59:
code_r0x0072faa1:
          return L"ERROR_RESOURCE_DATA_NOT_FOUND";
        case 0x5a:
code_r0x0072faab:
          return L"ERROR_RESOURCE_TYPE_NOT_FOUND";
        case 0x5b:
code_r0x0072fab5:
          return L"ERROR_RESOURCE_NAME_NOT_FOUND";
        case 0x5c:
code_r0x0072fabf:
          return L"ERROR_RESOURCE_LANG_NOT_FOUND";
        case 0x5d:
code_r0x0072fac9:
          return L"ERROR_NOT_ENOUGH_QUOTA";
        case 0x5e:
code_r0x0072fad3:
          return L"RPC_S_NO_INTERFACES";
        case 0x5f:
code_r0x0072fadd:
          return L"RPC_S_CALL_CANCELLED";
        case 0x60:
code_r0x0072fae7:
          return L"RPC_S_BINDING_INCOMPLETE";
        case 0x61:
code_r0x0072faf1:
          return L"RPC_S_COMM_FAILURE";
        case 0x62:
code_r0x0072fafb:
          return L"RPC_S_UNSUPPORTED_AUTHN_LEVEL";
        case 99:
code_r0x0072fb05:
          return L"RPC_S_NO_PRINC_NAME";
        case 100:
LAB_0072fc31:
          return L"RPC_S_NOT_RPC_ERROR";
        case 0x65:
code_r0x0072fc5b:
          return L"RPC_S_UUID_LOCAL_ONLY";
        case 0x66:
code_r0x0072fc65:
          return L"RPC_S_SEC_PKG_ERROR";
        case 0x67:
code_r0x0072fc6f:
          return L"RPC_S_NOT_CANCELLED";
        case 0x68:
code_r0x0072fc79:
          return L"RPC_X_INVALID_ES_ACTION";
        case 0x69:
code_r0x0072fc83:
          return L"RPC_X_WRONG_ES_VERSION";
        case 0x6a:
code_r0x0072fc8d:
          return L"RPC_X_WRONG_STUB_VERSION";
        case 0x6b:
code_r0x0072fc97:
          return L"RPC_X_INVALID_PIPE_OBJECT";
        case 0x6c:
code_r0x0072fca1:
          return L"RPC_X_WRONG_PIPE_ORDER";
        case 0x6d:
code_r0x0072fcab:
          return L"RPC_X_WRONG_PIPE_VERSION";
        case 0x6e:
LAB_0072fcb5:
          return L"RPC_S_GROUP_MEMBER_NOT_FOUND";
        case 0x6f:
code_r0x0072fce7:
          return L"EPT_S_CANT_CREATE";
        case 0x70:
code_r0x0072fcf1:
          return L"RPC_S_INVALID_OBJECT";
        case 0x71:
code_r0x0072fcfb:
          return L"ERROR_INVALID_TIME";
        case 0x72:
code_r0x0072fd05:
          return L"ERROR_INVALID_FORM_NAME";
        case 0x73:
code_r0x0072fd0f:
          return L"ERROR_INVALID_FORM_SIZE";
        case 0x74:
code_r0x0072fd19:
          return L"ERROR_ALREADY_WAITING";
        case 0x75:
code_r0x0072fd23:
          return L"ERROR_PRINTER_DELETED";
        case 0x76:
code_r0x0072fd2d:
          return L"ERROR_INVALID_PRINTER_STATE";
        case 0x77:
code_r0x0072fd37:
          return L"ERROR_PASSWORD_MUST_CHANGE";
        case 0x78:
code_r0x0072fd41:
          return L"ERROR_DOMAIN_CONTROLLER_NOT_FOUND";
        case 0x79:
code_r0x0072fd4b:
          return L"ERROR_ACCOUNT_LOCKED_OUT";
        case 0x7a:
code_r0x0072fd55:
          return L"OR_INVALID_OXID";
        case 0x7b:
code_r0x0072fd5f:
          return L"OR_INVALID_OID";
        case 0x7c:
code_r0x0072fd69:
          return L"OR_INVALID_SET";
        case 0x7d:
code_r0x0072fd73:
          return L"RPC_S_SEND_INCOMPLETE";
        case 0x7e:
code_r0x0072fd7d:
          return L"RPC_S_INVALID_ASYNC_HANDLE";
        case 0x7f:
code_r0x0072fd87:
          return L"RPC_S_INVALID_ASYNC_CALL";
        case 0x80:
code_r0x0072fd91:
          return L"RPC_X_PIPE_CLOSED";
        case 0x81:
code_r0x0072fd9b:
          return L"RPC_X_PIPE_DISCIPLINE_ERROR";
        case 0x82:
code_r0x0072fda5:
          return L"RPC_X_PIPE_EMPTY";
        case 0x83:
code_r0x0072fdaf:
          return L"ERROR_NO_SITENAME";
        case 0x84:
code_r0x0072fdb9:
          return L"ERROR_CANT_ACCESS_FILE";
        case 0x85:
code_r0x0072fdc3:
          return L"ERROR_CANT_RESOLVE_FILENAME";
        case 0x86:
code_r0x0072fdcd:
          return L"RPC_S_ENTRY_TYPE_MISMATCH";
        case 0x87:
code_r0x0072fdd7:
          return L"RPC_S_NOT_ALL_OBJS_EXPORTED";
        case 0x88:
code_r0x0072fde1:
          return L"RPC_S_INTERFACE_NOT_EXPORTED";
        case 0x89:
code_r0x0072fdeb:
          return L"RPC_S_PROFILE_NOT_ADDED";
        case 0x8a:
code_r0x0072fdf5:
          return L"RPC_S_PRF_ELT_NOT_ADDED";
        case 0x8b:
code_r0x0072fdff:
          return L"RPC_S_PRF_ELT_NOT_REMOVED";
        case 0x8c:
code_r0x0072fe09:
          return L"RPC_S_GRP_ELT_NOT_ADDED";
        case 0x8d:
code_r0x0072fe13:
          return L"RPC_S_GRP_ELT_NOT_REMOVED";
        case 0x8e:
code_r0x0072fe1d:
          return L"ERROR_KM_DRIVER_BLOCKED";
        case 0x8f:
code_r0x0072fe27:
          return L"ERROR_CONTEXT_EXPIRED";
        case 0x90:
LAB_0072fe31:
          return L"ERROR_INVALID_PIXEL_FORMAT";
        case 0x91:
code_r0x0072fe63:
          return L"ERROR_BAD_DRIVER";
        case 0x92:
code_r0x0072fe6d:
          return L"ERROR_INVALID_WINDOW_STYLE";
        case 0x93:
code_r0x0072fe77:
          return L"ERROR_METAFILE_NOT_SUPPORTED";
        case 0x94:
code_r0x0072fe81:
          return L"ERROR_TRANSFORM_NOT_SUPPORTED";
        case 0x95:
code_r0x0072fe8b:
          return L"ERROR_CLIPPING_NOT_SUPPORTED";
        case 0x96:
code_r0x0072fe95:
          return L"ERROR_INVALID_CMM";
        case 0x97:
code_r0x0072fe9f:
          return L"ERROR_INVALID_PROFILE";
        case 0x98:
code_r0x0072fea9:
          return L"ERROR_TAG_NOT_FOUND";
        case 0x99:
code_r0x0072feb3:
          return L"ERROR_TAG_NOT_PRESENT";
        case 0x9a:
code_r0x0072febd:
          return L"ERROR_DUPLICATE_TAG";
        case 0x9b:
code_r0x0072fec7:
          return L"ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE";
        case 0x9c:
code_r0x0072fed1:
          return L"ERROR_PROFILE_NOT_FOUND";
        case 0x9d:
code_r0x0072fedb:
          return L"ERROR_INVALID_COLORSPACE";
        case 0x9e:
code_r0x0072fee5:
          return L"ERROR_ICM_NOT_ENABLED";
        case 0x9f:
code_r0x0072feef:
          return L"ERROR_DELETING_ICM_XFORM";
        case 0xa0:
code_r0x0072fef9:
          return L"ERROR_INVALID_TRANSFORM";
        case 0xa1:
code_r0x0072ff03:
          return L"ERROR_COLORSPACE_MISMATCH";
        case 0xa2:
code_r0x0072ff0d:
          return L"ERROR_INVALID_COLORINDEX";
        case 0xa3:
LAB_0072ff17:
          return L"ERROR_CONNECTED_OTHER_PASSWORD";
        case 0xa4:
LAB_0072ffbc:
          return L"ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT";
        case 0xa5:
LAB_0072ffb2:
          return L"ERROR_BAD_USERNAME";
        }
      }
    }
    else if (param_1 < -0x7ff8de83) {
      if (param_1 == -0x7ff8de84) {
LAB_007319a3:
        return L"ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4";
      }
      if (param_1 < -0x7ff8dfd5) {
        if (param_1 == -0x7ff8dfd6) {
LAB_00730db4:
          return L"ERROR_DS_AUTH_UNKNOWN";
        }
        if (param_1 < -0x7ff8ec3b) {
          if (param_1 == -0x7ff8ec3c) {
LAB_007306a1:
            return L"ERROR_CLUSTER_NETWORK_NOT_INTERNAL";
          }
          if (param_1 < -0x7ff8ef12) {
            if (param_1 == -0x7ff8ef13) {
LAB_0073038a:
              return L"ERROR_CLEANER_CARTRIDGE_SPENT";
            }
            if (param_1 < -0x7ff8ef8c) {
              if (param_1 == -0x7ff8ef8d) {
LAB_00730204:
                return L"ERROR_WMI_INVALID_REGINFO";
              }
              if (param_1 < -0x7ff8f05f) {
                if (param_1 == -0x7ff8f060) {
LAB_007300ca:
                  return L"ERROR_WINS_INTERNAL";
                }
                if (param_1 < -0x7ff8f441) {
                  if (param_1 == -0x7ff8f442) {
LAB_0072ffe4:
                    return L"ERROR_PRINT_MONITOR_ALREADY_INSTALLED";
                  }
                  if (param_1 < -0x7ff8f446) {
                    if (param_1 == -0x7ff8f447) {
LAB_0073000c:
                      return L"ERROR_PRINTER_DRIVER_IN_USE";
                    }
                    if (param_1 == -0x7ff8f69f) {
LAB_0072ff9e:
                      return L"ERROR_OPEN_FILES";
                    }
                    if (param_1 == -0x7ff8f69e) {
LAB_0072ff94:
                      return L"ERROR_ACTIVE_CONNECTIONS";
                    }
                    if (param_1 == -0x7ff8f69c) {
LAB_0072ff8a:
                      return L"ERROR_DEVICE_IN_USE";
                    }
                    if (param_1 == -0x7ff8f448) goto LAB_00729e7d;
                  }
                  else {
                    if (param_1 == -0x7ff8f446) {
LAB_00730002:
                      return L"ERROR_SPOOL_FILE_NOT_FOUND";
                    }
                    if (param_1 == -0x7ff8f445) {
LAB_0072fff8:
                      return L"ERROR_SPL_NO_STARTDOC";
                    }
                    if (param_1 == -0x7ff8f444) {
LAB_0072ffee:
                      return L"ERROR_SPL_NO_ADDJOB";
                    }
                    if (param_1 == -0x7ff8f443) {
LAB_00729eb3:
                      return L"ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED";
                    }
                  }
                }
                else {
                  switch(param_1) {
                  case -0x7ff8f441:
LAB_00730016:
                    return L"ERROR_INVALID_PRINT_MONITOR";
                  case -0x7ff8f440:
LAB_00730077:
                    return L"ERROR_PRINT_MONITOR_IN_USE";
                  case -0x7ff8f43f:
LAB_0073006d:
                    return L"ERROR_PRINTER_HAS_JOBS_QUEUED";
                  case -0x7ff8f43e:
LAB_00730063:
                    return L"ERROR_SUCCESS_REBOOT_REQUIRED";
                  case -0x7ff8f43d:
LAB_00730059:
                    return L"ERROR_SUCCESS_RESTART_REQUIRED";
                  case -0x7ff8f43c:
LAB_0073004f:
                    return L"ERROR_PRINTER_NOT_FOUND";
                  case -0x7ff8f43b:
code_r0x00730045:
                    return L"ERROR_PRINTER_DRIVER_WARNED";
                  case -0x7ff8f43a:
LAB_00730081:
                    return L"ERROR_PRINTER_DRIVER_BLOCKED";
                  }
                }
              }
              else if (param_1 < -0x7ff8ef95) {
                if (param_1 == -0x7ff8ef96) {
LAB_00730126:
                  return L"ERROR_WMI_ITEMID_NOT_FOUND";
                }
                if (param_1 < -0x7ff8f05a) {
                  if (param_1 == -0x7ff8f05b) goto LAB_007300d4;
                  if (param_1 == -0x7ff8f05f) {
LAB_007300c0:
                    return L"ERROR_CAN_NOT_DEL_LOCAL_WINS";
                  }
                  if (param_1 == -0x7ff8f05e) {
LAB_007300b6:
                    return L"ERROR_STATIC_INIT";
                  }
                  if (param_1 == -0x7ff8f05d) {
LAB_007300ac:
                    return L"ERROR_INC_BACKUP";
                  }
                  if (param_1 == -0x7ff8f05c) {
LAB_007300a2:
                    return L"ERROR_FULL_BACKUP";
                  }
                }
                else {
                  if (param_1 == -0x7ff8f05a) {
LAB_00730144:
                    return L"ERROR_RPL_NOT_ALLOWED";
                  }
                  if (param_1 == -0x7ff8effc) {
LAB_0073013a:
                    return L"ERROR_DHCP_ADDRESS_CONFLICT";
                  }
                  if (param_1 == -0x7ff8ef98) {
LAB_00730130:
                    return L"ERROR_WMI_GUID_NOT_FOUND";
                  }
                  if (param_1 == -0x7ff8ef97) {
LAB_00729f4d:
                    return L"ERROR_WMI_INSTANCE_NOT_FOUND";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ff8ef95:
code_r0x0073011c:
                  return L"ERROR_WMI_TRY_AGAIN";
                case -0x7ff8ef94:
LAB_0073014e:
                  return L"ERROR_WMI_DP_NOT_FOUND";
                case -0x7ff8ef93:
LAB_00730197:
                  return L"ERROR_WMI_UNRESOLVED_INSTANCE_REF";
                case -0x7ff8ef92:
LAB_0073018d:
                  return L"ERROR_WMI_ALREADY_ENABLED";
                case -0x7ff8ef91:
LAB_00730183:
                  return L"ERROR_WMI_GUID_DISCONNECTED";
                case -0x7ff8ef90:
LAB_00730179:
                  return L"ERROR_WMI_SERVER_UNAVAILABLE";
                case -0x7ff8ef8f:
code_r0x0073016f:
                  return L"ERROR_WMI_DP_FAILED";
                case -0x7ff8ef8e:
LAB_007301a1:
                  return L"ERROR_WMI_INVALID_MOF";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8ef8c:
LAB_007301fa:
                return L"ERROR_WMI_ALREADY_DISABLED";
              case -0x7ff8ef8b:
LAB_007301f0:
                return L"ERROR_WMI_READ_ONLY";
              case -0x7ff8ef8a:
LAB_007301e6:
                return L"ERROR_WMI_SET_FAILURE";
              case -0x7ff8ef34:
LAB_007301dc:
                return L"ERROR_INVALID_MEDIA";
              case -0x7ff8ef33:
code_r0x007301d2:
                return L"ERROR_INVALID_LIBRARY";
              case -0x7ff8ef32:
LAB_0073020e:
                return L"ERROR_INVALID_MEDIA_POOL";
              case -0x7ff8ef31:
LAB_00730257:
                return L"ERROR_DRIVE_MEDIA_MISMATCH";
              case -0x7ff8ef30:
LAB_0073024d:
                return L"ERROR_MEDIA_OFFLINE";
              case -0x7ff8ef2f:
LAB_00730243:
                return L"ERROR_LIBRARY_OFFLINE";
              case -0x7ff8ef2e:
LAB_00730239:
                return L"ERROR_EMPTY";
              case -0x7ff8ef2d:
code_r0x0073022f:
                return L"ERROR_NOT_EMPTY";
              case -0x7ff8ef2c:
LAB_00730261:
                return L"ERROR_MEDIA_UNAVAILABLE";
              case -0x7ff8ef2b:
code_r0x0073029a:
                return L"ERROR_RESOURCE_DISABLED";
              case -0x7ff8ef2a:
code_r0x007302a4:
                return L"ERROR_INVALID_CLEANER";
              case -0x7ff8ef29:
code_r0x007302ae:
                return L"ERROR_UNABLE_TO_CLEAN";
              case -0x7ff8ef28:
code_r0x007302b8:
                return L"ERROR_OBJECT_NOT_FOUND";
              case -0x7ff8ef27:
code_r0x007302c2:
                return L"ERROR_DATABASE_FAILURE";
              case -0x7ff8ef26:
code_r0x007302cc:
                return L"ERROR_DATABASE_FULL";
              case -0x7ff8ef25:
code_r0x007302d6:
                return L"ERROR_MEDIA_INCOMPATIBLE";
              case -0x7ff8ef24:
code_r0x007302e0:
                return L"ERROR_RESOURCE_NOT_PRESENT";
              case -0x7ff8ef23:
code_r0x007302ea:
                return L"ERROR_INVALID_OPERATION";
              case -0x7ff8ef22:
code_r0x007302f4:
                return L"ERROR_MEDIA_NOT_AVAILABLE";
              case -0x7ff8ef21:
code_r0x007302fe:
                return L"ERROR_DEVICE_NOT_AVAILABLE";
              case -0x7ff8ef20:
code_r0x00730308:
                return L"ERROR_REQUEST_REFUSED";
              case -0x7ff8ef1f:
code_r0x00730312:
                return L"ERROR_INVALID_DRIVE_OBJECT";
              case -0x7ff8ef1e:
code_r0x0073031c:
                return L"ERROR_LIBRARY_FULL";
              case -0x7ff8ef1d:
code_r0x00730326:
                return L"ERROR_MEDIUM_NOT_ACCESSIBLE";
              case -0x7ff8ef1c:
code_r0x00730330:
                return L"ERROR_UNABLE_TO_LOAD_MEDIUM";
              case -0x7ff8ef1b:
code_r0x0073033a:
                return L"ERROR_UNABLE_TO_INVENTORY_DRIVE";
              case -0x7ff8ef1a:
code_r0x00730344:
                return L"ERROR_UNABLE_TO_INVENTORY_SLOT";
              case -0x7ff8ef19:
code_r0x0073034e:
                return L"ERROR_UNABLE_TO_INVENTORY_TRANSPORT";
              case -0x7ff8ef18:
code_r0x00730358:
                return L"ERROR_TRANSPORT_FULL";
              case -0x7ff8ef17:
code_r0x00730362:
                return L"ERROR_CONTROLLING_IEPORT";
              case -0x7ff8ef16:
code_r0x0073036c:
                return L"ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA";
              case -0x7ff8ef15:
code_r0x00730376:
                return L"ERROR_CLEANER_SLOT_SET";
              case -0x7ff8ef14:
code_r0x00730380:
                return L"ERROR_CLEANER_SLOT_NOT_SET";
              }
            }
          }
          else if (param_1 < -0x7ff8eed9) {
            if (param_1 == -0x7ff8eeda) {
LAB_007303d0:
              return L"ERROR_NOT_A_REPARSE_POINT";
            }
            switch(param_1) {
            case -0x7ff8ef12:
code_r0x00730394:
              return L"ERROR_UNEXPECTED_OMID";
            case -0x7ff8ef11:
code_r0x0073039e:
              return L"ERROR_CANT_DELETE_LAST_ITEM";
            case -0x7ff8ef10:
code_r0x007303a8:
              return L"ERROR_MESSAGE_EXCEEDS_MAX_SIZE";
            case -0x7ff8ef0f:
code_r0x007303ee:
              return L"ERROR_VOLUME_CONTAINS_SYS_FILES";
            case -0x7ff8ef0e:
code_r0x007303f8:
              return L"ERROR_INDIGENOUS_TYPE";
            case -0x7ff8ef0d:
code_r0x00730402:
              return L"ERROR_NO_SUPPORTING_DRIVES";
            case -0x7ff8ef0c:
code_r0x0073040c:
              return L"ERROR_CLEANER_CARTRIDGE_INSTALLED";
            case -0x7ff8ef02:
code_r0x007303b2:
              return L"ERROR_FILE_OFFLINE";
            case -0x7ff8ef01:
code_r0x007303bc:
              return L"ERROR_REMOTE_STORAGE_NOT_ACTIVE";
            case -0x7ff8ef00:
code_r0x007303c6:
              return L"ERROR_REMOTE_STORAGE_MEDIA_ERROR";
            }
          }
          else if (param_1 < -0x7ff8ec5c) {
            if (param_1 == -0x7ff8ec5d) goto LAB_00730561;
            if (param_1 < -0x7ff8ec6c) {
              if (param_1 == -0x7ff8ec6d) goto LAB_00730499;
              if (param_1 < -0x7ff8ec74) {
                if (param_1 == -0x7ff8ec75) goto LAB_00730453;
                if (param_1 == -0x7ff8eed9) goto LAB_007303da;
                if (param_1 == -0x7ff8eed8) goto LAB_007303e4;
                if (param_1 == -0x7ff8eed7) goto LAB_00730416;
                if (param_1 == -0x7ff8eed6) goto LAB_00730420;
                if (param_1 == -0x7ff8ee6c) goto LAB_0073042a;
                if (param_1 == -0x7ff8ec77) goto LAB_00730449;
                if (param_1 == -0x7ff8ec76) goto code_r0x0072a033;
              }
              else {
                if (param_1 == -0x7ff8ec74) goto LAB_0073045d;
                if (param_1 == -0x7ff8ec73) goto LAB_00730467;
                if (param_1 == -0x7ff8ec72) goto LAB_00730471;
                if (param_1 == -0x7ff8ec71) goto LAB_0073047b;
                if (param_1 == -0x7ff8ec70) goto LAB_00730485;
                if (param_1 == -0x7ff8ec6f) goto LAB_0073048f;
                if (param_1 == -0x7ff8ec6e) goto code_r0x0072a08a;
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8ec6c:
                goto LAB_007304a3;
              case -0x7ff8ec6b:
                goto code_r0x007304d5;
              case -0x7ff8ec6a:
                goto code_r0x007304df;
              case -0x7ff8ec69:
                goto code_r0x007304e9;
              case -0x7ff8ec68:
                goto code_r0x007304f3;
              case -0x7ff8ec67:
                goto code_r0x007304fd;
              case -0x7ff8ec66:
                goto code_r0x00730507;
              case -0x7ff8ec65:
                goto code_r0x00730511;
              case -0x7ff8ec64:
                goto code_r0x0073051b;
              case -0x7ff8ec63:
                goto code_r0x00730525;
              case -0x7ff8ec62:
                goto code_r0x0073052f;
              case -0x7ff8ec61:
                goto code_r0x00730539;
              case -0x7ff8ec60:
                goto code_r0x00730543;
              case -0x7ff8ec5f:
                goto code_r0x0073054d;
              case -0x7ff8ec5e:
                goto code_r0x00730557;
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ff8ec5c:
              goto code_r0x0073056b;
            case -0x7ff8ec5b:
              goto code_r0x00730575;
            case -0x7ff8ec5a:
              goto code_r0x0073057f;
            case -0x7ff8ec59:
              goto code_r0x00730589;
            case -0x7ff8ec58:
              goto code_r0x00730593;
            case -0x7ff8ec57:
              goto code_r0x0073059d;
            case -0x7ff8ec56:
              goto code_r0x007305a7;
            case -0x7ff8ec55:
              goto code_r0x007305b1;
            case -0x7ff8ec54:
              goto code_r0x007305bb;
            case -0x7ff8ec53:
              goto code_r0x007305c5;
            case -0x7ff8ec52:
              goto code_r0x007305cf;
            case -0x7ff8ec51:
              goto code_r0x007305d9;
            case -0x7ff8ec50:
              goto code_r0x007305e3;
            case -0x7ff8ec4f:
              goto code_r0x007305ed;
            case -0x7ff8ec4e:
              goto code_r0x007305f7;
            case -0x7ff8ec4d:
              goto code_r0x00730601;
            case -0x7ff8ec4c:
              goto code_r0x0073060b;
            case -0x7ff8ec4b:
              goto code_r0x00730615;
            case -0x7ff8ec4a:
              goto code_r0x0073061f;
            case -0x7ff8ec49:
              goto code_r0x00730629;
            case -0x7ff8ec48:
              goto code_r0x00730633;
            case -0x7ff8ec47:
              goto code_r0x0073063d;
            case -0x7ff8ec46:
              goto code_r0x00730647;
            case -0x7ff8ec45:
              goto code_r0x00730651;
            case -0x7ff8ec44:
              goto code_r0x0073065b;
            case -0x7ff8ec43:
              goto code_r0x00730665;
            case -0x7ff8ec42:
              goto code_r0x0073066f;
            case -0x7ff8ec40:
              goto code_r0x00730679;
            case -0x7ff8ec3f:
              goto code_r0x00730683;
            case -0x7ff8ec3e:
              goto code_r0x0073068d;
            case -0x7ff8ec3d:
              goto code_r0x00730697;
            }
          }
        }
        else if (param_1 < -0x7ff8e8fd) {
          if (param_1 == -0x7ff8e8fe) goto LAB_007307cd;
          switch(param_1) {
          case -0x7ff8ec3b:
            goto code_r0x007306ab;
          case -0x7ff8ec3a:
            goto code_r0x007306b5;
          case -0x7ff8ec39:
            goto code_r0x007306bf;
          case -0x7ff8ec38:
            goto code_r0x007306c9;
          case -0x7ff8ec37:
            goto code_r0x007306d3;
          case -0x7ff8ec36:
            goto code_r0x007306dd;
          case -0x7ff8ec35:
            goto code_r0x007306e7;
          case -0x7ff8ec34:
            goto code_r0x007306f1;
          case -0x7ff8ec33:
            goto code_r0x007306fb;
          case -0x7ff8ec32:
            goto code_r0x00730705;
          case -0x7ff8ec31:
            goto code_r0x0073070f;
          case -0x7ff8ec30:
            goto code_r0x00730719;
          case -0x7ff8ec2f:
            goto code_r0x00730723;
          case -0x7ff8ec2e:
            goto code_r0x0073072d;
          case -0x7ff8ec2d:
            goto code_r0x00730737;
          case -0x7ff8ec2c:
            goto code_r0x00730741;
          case -0x7ff8ec2b:
            goto code_r0x0073074b;
          case -0x7ff8ec2a:
            goto code_r0x00730755;
          case -0x7ff8ec29:
            goto code_r0x0073075f;
          case -0x7ff8ec28:
            goto code_r0x00730769;
          case -0x7ff8ec27:
            goto code_r0x00730773;
          case -0x7ff8ec26:
            goto code_r0x0073077d;
          case -0x7ff8ec25:
            goto code_r0x00730787;
          case -0x7ff8ec24:
            goto code_r0x00730791;
          case -0x7ff8ec23:
            goto code_r0x0073079b;
          case -0x7ff8ec22:
            goto code_r0x007307a5;
          case -0x7ff8ec21:
            goto code_r0x007307af;
          case -0x7ff8ec20:
            goto code_r0x007307b9;
          case -0x7ff8ec1f:
            goto code_r0x007307c3;
          }
        }
        else if (param_1 < -0x7ff8e88f) {
          if (param_1 == -0x7ff8e890) goto LAB_0073085f;
          switch(param_1) {
          case -0x7ff8e8fd:
            goto code_r0x007307fb;
          case -0x7ff8e8fc:
            goto code_r0x00730805;
          case -0x7ff8e8fb:
            goto code_r0x0073080f;
          case -0x7ff8e8fa:
            goto code_r0x00730819;
          case -0x7ff8e8f9:
            goto code_r0x00730823;
          case -0x7ff8e8f8:
            goto code_r0x0073082d;
          case -0x7ff8e8f7:
            goto code_r0x00730837;
          case -0x7ff8e8f6:
            goto code_r0x00730841;
          case -0x7ff8e8f5:
            goto code_r0x0073084b;
          case -0x7ff8e8f4:
            goto code_r0x00730855;
          }
        }
        else if (param_1 < -0x7ff8e819) {
          if (param_1 == -0x7ff8e81a) goto LAB_00730931;
          switch(param_1) {
          case -0x7ff8e88f:
            goto code_r0x00730891;
          case -0x7ff8e88e:
            goto code_r0x0073089b;
          case -0x7ff8e88d:
            goto code_r0x007308a5;
          case -0x7ff8e88c:
            goto code_r0x007308af;
          case -0x7ff8e88b:
            goto code_r0x007308b9;
          case -0x7ff8e88a:
            goto code_r0x007308c3;
          case -0x7ff8e889:
            goto code_r0x007308cd;
          case -0x7ff8e888:
            goto code_r0x007308d7;
          case -0x7ff8e887:
            goto code_r0x007308e1;
          case -0x7ff8e886:
            goto code_r0x007308eb;
          case -0x7ff8e885:
            goto code_r0x007308f5;
          case -0x7ff8e884:
            goto code_r0x007308ff;
          case -0x7ff8e883:
            goto code_r0x00730909;
          case -0x7ff8e882:
            goto code_r0x00730913;
          case -0x7ff8e881:
            goto code_r0x0073091d;
          case -0x7ff8e880:
            goto code_r0x00730927;
          }
        }
        else if (param_1 < -0x7ff8e0b9) {
          if (param_1 == -0x7ff8e0ba) {
LAB_00730bdd:
            return L"FRS_ERR_SERVICE_COMM";
          }
          if (param_1 < -0x7ff8e484) {
            if (param_1 == -0x7ff8e485) {
LAB_00730ab5:
              return L"ERROR_CTX_GRAPHICS_INVALID";
            }
            if (param_1 < -0x7ff8e49c) {
              if (param_1 == -0x7ff8e49d) {
LAB_00730a2b:
                return L"ERROR_CTX_MODEM_RESPONSE_ERROR";
              }
              if (param_1 < -0x7ff8e4a2) {
                if (param_1 == -0x7ff8e4a3) {
LAB_007309bd:
                  return L"ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY";
                }
                if (param_1 == -0x7ff8e7c8) {
LAB_007309e5:
                  return L"SCHED_E_SERVICE_NOT_LOCALSYSTEM";
                }
                if (param_1 == -0x7ff8e4a7) {
LAB_007309db:
                  return L"ERROR_CTX_WINSTATION_NAME_INVALID";
                }
                if (param_1 == -0x7ff8e4a6) {
LAB_007309d1:
                  return L"ERROR_CTX_INVALID_PD";
                }
                if (param_1 == -0x7ff8e4a5) {
LAB_007309c7:
                  return L"ERROR_CTX_PD_NOT_FOUND";
                }
                if (param_1 == -0x7ff8e4a4) {
LAB_0072a1a7:
                  return L"ERROR_CTX_WD_NOT_FOUND";
                }
              }
              else {
                if (param_1 == -0x7ff8e4a2) {
LAB_007309b3:
                  return L"ERROR_CTX_SERVICE_NAME_COLLISION";
                }
                if (param_1 == -0x7ff8e4a1) goto LAB_007309ef;
                if (param_1 == -0x7ff8e4a0) goto LAB_00730a3f;
                if (param_1 == -0x7ff8e49f) goto LAB_00730a35;
                if (param_1 == -0x7ff8e49e) goto LAB_0072a1e8;
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8e49c:
LAB_00730a21:
                return L"ERROR_CTX_MODEM_RESPONSE_TIMEOUT";
              case -0x7ff8e49b:
code_r0x00730a17:
                return L"ERROR_CTX_MODEM_RESPONSE_NO_CARRIER";
              case -0x7ff8e49a:
LAB_00730a49:
                return L"ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE";
              case -0x7ff8e499:
code_r0x00730a6f:
                return L"ERROR_CTX_MODEM_RESPONSE_BUSY";
              case -0x7ff8e498:
code_r0x00730a79:
                return L"ERROR_CTX_MODEM_RESPONSE_VOICE";
              case -0x7ff8e497:
code_r0x00730a83:
                return L"ERROR_CTX_TD_ERROR";
              case -0x7ff8e492:
code_r0x00730a8d:
                return L"ERROR_CTX_WINSTATION_NOT_FOUND";
              case -0x7ff8e491:
code_r0x00730a97:
                return L"ERROR_CTX_WINSTATION_ALREADY_EXISTS";
              case -0x7ff8e490:
code_r0x00730aa1:
                return L"ERROR_CTX_WINSTATION_BUSY";
              case -0x7ff8e48f:
code_r0x00730aab:
                return L"ERROR_CTX_BAD_VIDEO_MODE";
              }
            }
          }
          else if (param_1 < -0x7ff8e0be) {
            if (param_1 == -0x7ff8e0bf) {
LAB_00730b8d:
              return L"FRS_ERR_INVALID_API_SEQUENCE";
            }
            switch(param_1) {
            case -0x7ff8e483:
code_r0x00730abf:
              return L"ERROR_CTX_LOGON_DISABLED";
            case -0x7ff8e482:
code_r0x00730ac9:
              return L"ERROR_CTX_NOT_CONSOLE";
            case -0x7ff8e480:
code_r0x00730ad3:
              return L"ERROR_CTX_CLIENT_QUERY_TIMEOUT";
            case -0x7ff8e47f:
code_r0x00730add:
              return L"ERROR_CTX_CONSOLE_DISCONNECT";
            case -0x7ff8e47e:
code_r0x00730ae7:
              return L"ERROR_CTX_CONSOLE_CONNECT";
            case -0x7ff8e47c:
code_r0x00730af1:
              return L"ERROR_CTX_SHADOW_DENIED";
            case -0x7ff8e47b:
              goto LAB_00730afb;
            case -0x7ff8e477:
code_r0x00730b29:
              return L"ERROR_CTX_INVALID_WD";
            case -0x7ff8e476:
code_r0x00730b33:
              return L"ERROR_CTX_SHADOW_INVALID";
            case -0x7ff8e475:
code_r0x00730b3d:
              return L"ERROR_CTX_SHADOW_DISABLED";
            case -0x7ff8e474:
code_r0x00730b47:
              return L"ERROR_CTX_CLIENT_LICENSE_IN_USE";
            case -0x7ff8e473:
code_r0x00730b51:
              return L"ERROR_CTX_CLIENT_LICENSE_NOT_SET";
            case -0x7ff8e472:
code_r0x00730b5b:
              return L"ERROR_CTX_LICENSE_NOT_AVAILABLE";
            case -0x7ff8e471:
code_r0x00730b65:
              return L"ERROR_CTX_LICENSE_CLIENT_INVALID";
            case -0x7ff8e470:
code_r0x00730b6f:
              return L"ERROR_CTX_LICENSE_EXPIRED";
            case -0x7ff8e46f:
code_r0x00730b79:
              return L"ERROR_CTX_SHADOW_NOT_RUNNING";
            case -0x7ff8e46e:
code_r0x00730b83:
              return L"ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE";
            }
          }
          else {
            if (param_1 == -0x7ff8e0be) {
LAB_00730bbf:
              return L"FRS_ERR_STARTING_SERVICE";
            }
            if (param_1 == -0x7ff8e0bd) {
LAB_00730bc9:
              return L"FRS_ERR_STOPPING_SERVICE";
            }
            if (param_1 == -0x7ff8e0bc) {
LAB_00730bd3:
              return L"FRS_ERR_INTERNAL_API";
            }
            if (param_1 == -0x7ff8e0bb) goto code_r0x0072a257;
          }
        }
        else if (param_1 < -0x7ff8dff7) {
          if (param_1 == -0x7ff8dff8) {
LAB_00730c55:
            return L"ERROR_DS_NOT_INSTALLED";
          }
          switch(param_1) {
          case -0x7ff8e0b9:
code_r0x00730be7:
            return L"FRS_ERR_INSUFFICIENT_PRIV";
          case -0x7ff8e0b8:
code_r0x00730bf1:
            return L"FRS_ERR_AUTHENTICATION";
          case -0x7ff8e0b7:
code_r0x00730bfb:
            return L"FRS_ERR_PARENT_INSUFFICIENT_PRIV";
          case -0x7ff8e0b6:
code_r0x00730c05:
            return L"FRS_ERR_PARENT_AUTHENTICATION";
          case -0x7ff8e0b5:
code_r0x00730c0f:
            return L"FRS_ERR_CHILD_TO_PARENT_COMM";
          case -0x7ff8e0b4:
code_r0x00730c19:
            return L"FRS_ERR_PARENT_TO_CHILD_COMM";
          case -0x7ff8e0b3:
code_r0x00730c23:
            return L"FRS_ERR_SYSVOL_POPULATE";
          case -0x7ff8e0b2:
code_r0x00730c2d:
            return L"FRS_ERR_SYSVOL_POPULATE_TIMEOUT";
          case -0x7ff8e0b1:
code_r0x00730c37:
            return L"FRS_ERR_SYSVOL_IS_BUSY";
          case -0x7ff8e0b0:
code_r0x00730c41:
            return L"FRS_ERR_SYSVOL_DEMOTE";
          case -0x7ff8e0af:
code_r0x00730c4b:
            return L"FRS_ERR_INVALID_SERVICE_PARAMETER";
          }
        }
        else {
          switch(param_1) {
          case -0x7ff8dff7:
            goto LAB_00730c5f;
          case -0x7ff8dff6:
            goto code_r0x00730c7e;
          case -0x7ff8dff5:
            goto code_r0x00730c88;
          case -0x7ff8dff4:
            goto code_r0x00730c92;
          case -0x7ff8dff3:
            goto code_r0x00730c9c;
          case -0x7ff8dff2:
            goto code_r0x00730ca6;
          case -0x7ff8dff1:
            goto code_r0x00730cb0;
          case -0x7ff8dff0:
            goto code_r0x00730cba;
          case -0x7ff8dfef:
            goto code_r0x00730cc4;
          case -0x7ff8dfee:
            goto code_r0x00730cce;
          case -0x7ff8dfed:
            goto code_r0x00730cd8;
          case -0x7ff8dfec:
            goto code_r0x00730ce2;
          case -0x7ff8dfeb:
            goto code_r0x00730cec;
          case -0x7ff8dfea:
            goto code_r0x00730cf6;
          case -0x7ff8dfe9:
            goto code_r0x00730d00;
          case -0x7ff8dfe8:
            goto code_r0x00730d0a;
          case -0x7ff8dfe7:
            goto code_r0x00730d14;
          case -0x7ff8dfe6:
            goto code_r0x00730d1e;
          case -0x7ff8dfe5:
            goto code_r0x00730d28;
          case -0x7ff8dfe4:
            goto code_r0x00730d32;
          case -0x7ff8dfe3:
            goto code_r0x00730d3c;
          case -0x7ff8dfe2:
            goto code_r0x00730d46;
          case -0x7ff8dfe0:
            goto code_r0x00730d50;
          case -0x7ff8dfdf:
            goto code_r0x00730d5a;
          case -0x7ff8dfde:
            goto code_r0x00730d64;
          case -0x7ff8dfdd:
            goto code_r0x00730d6e;
          case -0x7ff8dfdc:
            goto code_r0x00730d78;
          case -0x7ff8dfdb:
            goto code_r0x00730d82;
          case -0x7ff8dfda:
            goto code_r0x00730d8c;
          case -0x7ff8dfd9:
            goto code_r0x00730d96;
          case -0x7ff8dfd8:
            goto code_r0x00730da0;
          case -0x7ff8dfd7:
            goto code_r0x00730daa;
          }
        }
      }
      else {
        switch(param_1) {
        case -0x7ff8dfd5:
code_r0x00730dbe:
          return L"ERROR_DS_REFERRAL";
        case -0x7ff8dfd4:
code_r0x00730dc8:
          return L"ERROR_DS_UNAVAILABLE_CRIT_EXTENSION";
        case -0x7ff8dfd3:
code_r0x00730dd2:
          return L"ERROR_DS_CONFIDENTIALITY_REQUIRED";
        case -0x7ff8dfd2:
code_r0x00730ddc:
          return L"ERROR_DS_INAPPROPRIATE_MATCHING";
        case -0x7ff8dfd1:
code_r0x00730de6:
          return L"ERROR_DS_CONSTRAINT_VIOLATION";
        case -0x7ff8dfd0:
code_r0x00730df0:
          return L"ERROR_DS_NO_SUCH_OBJECT";
        case -0x7ff8dfcf:
code_r0x00730dfa:
          return L"ERROR_DS_ALIAS_PROBLEM";
        case -0x7ff8dfce:
code_r0x00730e04:
          return L"ERROR_DS_INVALID_DN_SYNTAX";
        case -0x7ff8dfcd:
code_r0x00730e0e:
          return L"ERROR_DS_IS_LEAF";
        case -0x7ff8dfcc:
code_r0x00730e18:
          return L"ERROR_DS_ALIAS_DEREF_PROBLEM";
        case -0x7ff8dfcb:
code_r0x00730e22:
          return L"ERROR_DS_UNWILLING_TO_PERFORM";
        case -0x7ff8dfca:
code_r0x00730e2c:
          return L"ERROR_DS_LOOP_DETECT";
        case -0x7ff8dfc9:
code_r0x00730e36:
          return L"ERROR_DS_NAMING_VIOLATION";
        case -0x7ff8dfc8:
code_r0x00730e40:
          return L"ERROR_DS_OBJECT_RESULTS_TOO_LARGE";
        case -0x7ff8dfc7:
code_r0x00730e4a:
          return L"ERROR_DS_AFFECTS_MULTIPLE_DSAS";
        case -0x7ff8dfc6:
code_r0x00730e54:
          return L"ERROR_DS_SERVER_DOWN";
        case -0x7ff8dfc5:
code_r0x00730e5e:
          return L"ERROR_DS_LOCAL_ERROR";
        case -0x7ff8dfc4:
code_r0x00730e68:
          return L"ERROR_DS_ENCODING_ERROR";
        case -0x7ff8dfc3:
code_r0x00730e72:
          return L"ERROR_DS_DECODING_ERROR";
        case -0x7ff8dfc2:
code_r0x00730e7c:
          return L"ERROR_DS_FILTER_UNKNOWN";
        case -0x7ff8dfc1:
code_r0x00730e86:
          return L"ERROR_DS_PARAM_ERROR";
        case -0x7ff8dfc0:
code_r0x00730e90:
          return L"ERROR_DS_NOT_SUPPORTED";
        case -0x7ff8dfbf:
code_r0x00730e9a:
          return L"ERROR_DS_NO_RESULTS_RETURNED";
        case -0x7ff8dfbe:
code_r0x00730ea4:
          return L"ERROR_DS_CONTROL_NOT_FOUND";
        case -0x7ff8dfbd:
code_r0x00730eae:
          return L"ERROR_DS_CLIENT_LOOP";
        case -0x7ff8dfbc:
LAB_00730eb8:
          return L"ERROR_DS_REFERRAL_LIMIT_EXCEEDED";
        case -0x7ff8dfbb:
code_r0x00731343:
          return L"ERROR_DS_SORT_CONTROL_MISSING";
        case -0x7ff8dfba:
code_r0x0073134d:
          return L"ERROR_DS_OFFSET_RANGE_ERROR";
        case -0x7ff8df93:
code_r0x00730ed9:
          return L"ERROR_DS_ROOT_MUST_BE_NC";
        case -0x7ff8df92:
code_r0x00730ee3:
          return L"ERROR_DS_ADD_REPLICA_INHIBITED";
        case -0x7ff8df91:
code_r0x00730eed:
          return L"ERROR_DS_ATT_NOT_DEF_IN_SCHEMA";
        case -0x7ff8df90:
code_r0x00730ef7:
          return L"ERROR_DS_MAX_OBJ_SIZE_EXCEEDED";
        case -0x7ff8df8f:
code_r0x00730f01:
          return L"ERROR_DS_OBJ_STRING_NAME_EXISTS";
        case -0x7ff8df8e:
code_r0x00730f0b:
          return L"ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA";
        case -0x7ff8df8d:
code_r0x00730f15:
          return L"ERROR_DS_RDN_DOESNT_MATCH_SCHEMA";
        case -0x7ff8df8c:
code_r0x00730f1f:
          return L"ERROR_DS_NO_REQUESTED_ATTS_FOUND";
        case -0x7ff8df8b:
code_r0x00730f29:
          return L"ERROR_DS_USER_BUFFER_TO_SMALL";
        case -0x7ff8df8a:
code_r0x00730f33:
          return L"ERROR_DS_ATT_IS_NOT_ON_OBJ";
        case -0x7ff8df89:
code_r0x00730f3d:
          return L"ERROR_DS_ILLEGAL_MOD_OPERATION";
        case -0x7ff8df88:
code_r0x00730f47:
          return L"ERROR_DS_OBJ_TOO_LARGE";
        case -0x7ff8df87:
code_r0x00730f51:
          return L"ERROR_DS_BAD_INSTANCE_TYPE";
        case -0x7ff8df86:
code_r0x00730f5b:
          return L"ERROR_DS_MASTERDSA_REQUIRED";
        case -0x7ff8df85:
code_r0x00730f65:
          return L"ERROR_DS_OBJECT_CLASS_REQUIRED";
        case -0x7ff8df84:
code_r0x00730f6f:
          return L"ERROR_DS_MISSING_REQUIRED_ATT";
        case -0x7ff8df83:
code_r0x00730f79:
          return L"ERROR_DS_ATT_NOT_DEF_FOR_CLASS";
        case -0x7ff8df82:
code_r0x00730f83:
          return L"ERROR_DS_ATT_ALREADY_EXISTS";
        case -0x7ff8df80:
code_r0x00730f8d:
          return L"ERROR_DS_CANT_ADD_ATT_VALUES";
        case -0x7ff8df7f:
code_r0x00730f97:
          return L"ERROR_DS_SINGLE_VALUE_CONSTRAINT";
        case -0x7ff8df7e:
code_r0x00730fa1:
          return L"ERROR_DS_RANGE_CONSTRAINT";
        case -0x7ff8df7d:
code_r0x00730fab:
          return L"ERROR_DS_ATT_VAL_ALREADY_EXISTS";
        case -0x7ff8df7c:
code_r0x00730fb5:
          return L"ERROR_DS_CANT_REM_MISSING_ATT";
        case -0x7ff8df7b:
code_r0x00730fbf:
          return L"ERROR_DS_CANT_REM_MISSING_ATT_VAL";
        case -0x7ff8df7a:
code_r0x00730fc9:
          return L"ERROR_DS_ROOT_CANT_BE_SUBREF";
        case -0x7ff8df79:
code_r0x00730fd3:
          return L"ERROR_DS_NO_CHAINING";
        case -0x7ff8df78:
code_r0x00730fdd:
          return L"ERROR_DS_NO_CHAINED_EVAL";
        case -0x7ff8df77:
code_r0x00730fe7:
          return L"ERROR_DS_NO_PARENT_OBJECT";
        case -0x7ff8df76:
code_r0x00730ff1:
          return L"ERROR_DS_PARENT_IS_AN_ALIAS";
        case -0x7ff8df75:
code_r0x00730ffb:
          return L"ERROR_DS_CANT_MIX_MASTER_AND_REPS";
        case -0x7ff8df74:
code_r0x00731005:
          return L"ERROR_DS_CHILDREN_EXIST";
        case -0x7ff8df73:
code_r0x0073100f:
          return L"ERROR_DS_OBJ_NOT_FOUND";
        case -0x7ff8df72:
code_r0x00731019:
          return L"ERROR_DS_ALIASED_OBJ_MISSING";
        case -0x7ff8df71:
code_r0x00731023:
          return L"ERROR_DS_BAD_NAME_SYNTAX";
        case -0x7ff8df70:
code_r0x0073102d:
          return L"ERROR_DS_ALIAS_POINTS_TO_ALIAS";
        case -0x7ff8df6f:
code_r0x00731037:
          return L"ERROR_DS_CANT_DEREF_ALIAS";
        case -0x7ff8df6e:
code_r0x00731041:
          return L"ERROR_DS_OUT_OF_SCOPE";
        case -0x7ff8df6d:
code_r0x00731357:
          return L"ERROR_DS_OBJECT_BEING_REMOVED";
        case -0x7ff8df6c:
code_r0x0073104b:
          return L"ERROR_DS_CANT_DELETE_DSA_OBJ";
        case -0x7ff8df6b:
code_r0x00731055:
          return L"ERROR_DS_GENERIC_ERROR";
        case -0x7ff8df6a:
code_r0x0073105f:
          return L"ERROR_DS_DSA_MUST_BE_INT_MASTER";
        case -0x7ff8df69:
code_r0x00731069:
          return L"ERROR_DS_CLASS_NOT_DSA";
        case -0x7ff8df68:
code_r0x00731073:
          return L"ERROR_DS_INSUFF_ACCESS_RIGHTS";
        case -0x7ff8df67:
code_r0x0073107d:
          return L"ERROR_DS_ILLEGAL_SUPERIOR";
        case -0x7ff8df66:
code_r0x00731087:
          return L"ERROR_DS_ATTRIBUTE_OWNED_BY_SAM";
        case -0x7ff8df65:
code_r0x00731091:
          return L"ERROR_DS_NAME_TOO_MANY_PARTS";
        case -0x7ff8df64:
code_r0x0073109b:
          return L"ERROR_DS_NAME_TOO_LONG";
        case -0x7ff8df63:
code_r0x007310a5:
          return L"ERROR_DS_NAME_VALUE_TOO_LONG";
        case -0x7ff8df62:
code_r0x007310af:
          return L"ERROR_DS_NAME_UNPARSEABLE";
        case -0x7ff8df61:
code_r0x007310b9:
          return L"ERROR_DS_NAME_TYPE_UNKNOWN";
        case -0x7ff8df60:
code_r0x007310c3:
          return L"ERROR_DS_NOT_AN_OBJECT";
        case -0x7ff8df5f:
code_r0x007310cd:
          return L"ERROR_DS_SEC_DESC_TOO_SHORT";
        case -0x7ff8df5e:
code_r0x007310d7:
          return L"ERROR_DS_SEC_DESC_INVALID";
        case -0x7ff8df5d:
code_r0x007310e1:
          return L"ERROR_DS_NO_DELETED_NAME";
        case -0x7ff8df5c:
code_r0x007310eb:
          return L"ERROR_DS_SUBREF_MUST_HAVE_PARENT";
        case -0x7ff8df5b:
code_r0x007310f5:
          return L"ERROR_DS_NCNAME_MUST_BE_NC";
        case -0x7ff8df5a:
code_r0x007310ff:
          return L"ERROR_DS_CANT_ADD_SYSTEM_ONLY";
        case -0x7ff8df59:
code_r0x00731109:
          return L"ERROR_DS_CLASS_MUST_BE_CONCRETE";
        case -0x7ff8df58:
code_r0x00731113:
          return L"ERROR_DS_INVALID_DMD";
        case -0x7ff8df57:
code_r0x0073111d:
          return L"ERROR_DS_OBJ_GUID_EXISTS";
        case -0x7ff8df56:
code_r0x00731127:
          return L"ERROR_DS_NOT_ON_BACKLINK";
        case -0x7ff8df55:
code_r0x00731131:
          return L"ERROR_DS_NO_CROSSREF_FOR_NC";
        case -0x7ff8df54:
code_r0x0073113b:
          return L"ERROR_DS_SHUTTING_DOWN";
        case -0x7ff8df53:
code_r0x00731145:
          return L"ERROR_DS_UNKNOWN_OPERATION";
        case -0x7ff8df52:
code_r0x0073114f:
          return L"ERROR_DS_INVALID_ROLE_OWNER";
        case -0x7ff8df51:
code_r0x00731159:
          return L"ERROR_DS_COULDNT_CONTACT_FSMO";
        case -0x7ff8df50:
code_r0x00731163:
          return L"ERROR_DS_CROSS_NC_DN_RENAME";
        case -0x7ff8df4f:
code_r0x0073116d:
          return L"ERROR_DS_CANT_MOD_SYSTEM_ONLY";
        case -0x7ff8df4e:
code_r0x00731177:
          return L"ERROR_DS_REPLICATOR_ONLY";
        case -0x7ff8df4d:
code_r0x00731181:
          return L"ERROR_DS_OBJ_CLASS_NOT_DEFINED";
        case -0x7ff8df4c:
code_r0x0073118b:
          return L"ERROR_DS_OBJ_CLASS_NOT_SUBCLASS";
        case -0x7ff8df4b:
code_r0x00731195:
          return L"ERROR_DS_NAME_REFERENCE_INVALID";
        case -0x7ff8df4a:
code_r0x0073119f:
          return L"ERROR_DS_CROSS_REF_EXISTS";
        case -0x7ff8df49:
code_r0x007311a9:
          return L"ERROR_DS_CANT_DEL_MASTER_CROSSREF";
        case -0x7ff8df48:
code_r0x007311b3:
          return L"ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD";
        case -0x7ff8df47:
code_r0x007311bd:
          return L"ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX";
        case -0x7ff8df46:
code_r0x007311c7:
          return L"ERROR_DS_DUP_RDN";
        case -0x7ff8df45:
code_r0x007311d1:
          return L"ERROR_DS_DUP_OID";
        case -0x7ff8df44:
code_r0x007311db:
          return L"ERROR_DS_DUP_MAPI_ID";
        case -0x7ff8df43:
code_r0x007311e5:
          return L"ERROR_DS_DUP_SCHEMA_ID_GUID";
        case -0x7ff8df42:
code_r0x007311ef:
          return L"ERROR_DS_DUP_LDAP_DISPLAY_NAME";
        case -0x7ff8df41:
code_r0x007311f9:
          return L"ERROR_DS_SEMANTIC_ATT_TEST";
        case -0x7ff8df40:
code_r0x00731203:
          return L"ERROR_DS_SYNTAX_MISMATCH";
        case -0x7ff8df3f:
code_r0x0073120d:
          return L"ERROR_DS_EXISTS_IN_MUST_HAVE";
        case -0x7ff8df3e:
code_r0x00731217:
          return L"ERROR_DS_EXISTS_IN_MAY_HAVE";
        case -0x7ff8df3d:
code_r0x00731221:
          return L"ERROR_DS_NONEXISTENT_MAY_HAVE";
        case -0x7ff8df3c:
code_r0x0073122b:
          return L"ERROR_DS_NONEXISTENT_MUST_HAVE";
        case -0x7ff8df3b:
code_r0x00731235:
          return L"ERROR_DS_AUX_CLS_TEST_FAIL";
        case -0x7ff8df3a:
code_r0x0073123f:
          return L"ERROR_DS_NONEXISTENT_POSS_SUP";
        case -0x7ff8df39:
code_r0x00731249:
          return L"ERROR_DS_SUB_CLS_TEST_FAIL";
        case -0x7ff8df38:
code_r0x00731253:
          return L"ERROR_DS_BAD_RDN_ATT_ID_SYNTAX";
        case -0x7ff8df37:
code_r0x0073125d:
          return L"ERROR_DS_EXISTS_IN_AUX_CLS";
        case -0x7ff8df36:
code_r0x00731267:
          return L"ERROR_DS_EXISTS_IN_SUB_CLS";
        case -0x7ff8df35:
code_r0x00731271:
          return L"ERROR_DS_EXISTS_IN_POSS_SUP";
        case -0x7ff8df34:
code_r0x0073127b:
          return L"ERROR_DS_RECALCSCHEMA_FAILED";
        case -0x7ff8df33:
code_r0x00731285:
          return L"ERROR_DS_TREE_DELETE_NOT_FINISHED";
        case -0x7ff8df32:
code_r0x0073128f:
          return L"ERROR_DS_CANT_DELETE";
        case -0x7ff8df31:
code_r0x00731299:
          return L"ERROR_DS_ATT_SCHEMA_REQ_ID";
        case -0x7ff8df30:
code_r0x007312a3:
          return L"ERROR_DS_BAD_ATT_SCHEMA_SYNTAX";
        case -0x7ff8df2f:
code_r0x007312ad:
          return L"ERROR_DS_CANT_CACHE_ATT";
        case -0x7ff8df2e:
code_r0x007312b7:
          return L"ERROR_DS_CANT_CACHE_CLASS";
        case -0x7ff8df2d:
code_r0x007312c1:
          return L"ERROR_DS_CANT_REMOVE_ATT_CACHE";
        case -0x7ff8df2c:
code_r0x007312cb:
          return L"ERROR_DS_CANT_REMOVE_CLASS_CACHE";
        case -0x7ff8df2b:
code_r0x007312d5:
          return L"ERROR_DS_CANT_RETRIEVE_DN";
        case -0x7ff8df2a:
code_r0x007312df:
          return L"ERROR_DS_MISSING_SUPREF";
        case -0x7ff8df29:
code_r0x007312e9:
          return L"ERROR_DS_CANT_RETRIEVE_INSTANCE";
        case -0x7ff8df28:
code_r0x007312f3:
          return L"ERROR_DS_CODE_INCONSISTENCY";
        case -0x7ff8df27:
code_r0x007312fd:
          return L"ERROR_DS_DATABASE_ERROR";
        case -0x7ff8df26:
code_r0x00731307:
          return L"ERROR_DS_GOVERNSID_MISSING";
        case -0x7ff8df25:
code_r0x00731311:
          return L"ERROR_DS_MISSING_EXPECTED_ATT";
        case -0x7ff8df24:
code_r0x0073131b:
          return L"ERROR_DS_NCNAME_MISSING_CR_REF";
        case -0x7ff8df23:
code_r0x00731325:
          return L"ERROR_DS_SECURITY_CHECKING_ERROR";
        case -0x7ff8df22:
code_r0x0073132f:
          return L"ERROR_DS_SCHEMA_NOT_LOADED";
        case -0x7ff8df21:
code_r0x00731339:
          return L"ERROR_DS_SCHEMA_ALLOC_FAILED";
        case -0x7ff8df20:
          goto LAB_00731361;
        case -0x7ff8df1f:
code_r0x00731395:
          return L"ERROR_DS_GCVERIFY_ERROR";
        case -0x7ff8df1e:
code_r0x0073139f:
          return L"ERROR_DS_DRA_SCHEMA_MISMATCH";
        case -0x7ff8df1d:
code_r0x007313a9:
          return L"ERROR_DS_CANT_FIND_DSA_OBJ";
        case -0x7ff8df1c:
code_r0x007313b3:
          return L"ERROR_DS_CANT_FIND_EXPECTED_NC";
        case -0x7ff8df1b:
code_r0x007313bd:
          return L"ERROR_DS_CANT_FIND_NC_IN_CACHE";
        case -0x7ff8df1a:
code_r0x007313c7:
          return L"ERROR_DS_CANT_RETRIEVE_CHILD";
        case -0x7ff8df19:
code_r0x007313d1:
          return L"ERROR_DS_SECURITY_ILLEGAL_MODIFY";
        case -0x7ff8df18:
code_r0x007313db:
          return L"ERROR_DS_CANT_REPLACE_HIDDEN_REC";
        case -0x7ff8df17:
code_r0x007313e5:
          return L"ERROR_DS_BAD_HIERARCHY_FILE";
        case -0x7ff8df16:
code_r0x007313ef:
          return L"ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED";
        case -0x7ff8df15:
code_r0x007313f9:
          return L"ERROR_DS_CONFIG_PARAM_MISSING";
        case -0x7ff8df14:
code_r0x00731403:
          return L"ERROR_DS_COUNTING_AB_INDICES_FAILED";
        case -0x7ff8df13:
code_r0x0073140d:
          return L"ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED";
        case -0x7ff8df12:
code_r0x00731417:
          return L"ERROR_DS_INTERNAL_FAILURE";
        case -0x7ff8df11:
code_r0x00731421:
          return L"ERROR_DS_UNKNOWN_ERROR";
        case -0x7ff8df10:
code_r0x0073142b:
          return L"ERROR_DS_ROOT_REQUIRES_CLASS_TOP";
        case -0x7ff8df0f:
code_r0x00731435:
          return L"ERROR_DS_REFUSING_FSMO_ROLES";
        case -0x7ff8df0e:
code_r0x0073143f:
          return L"ERROR_DS_MISSING_FSMO_SETTINGS";
        case -0x7ff8df0d:
code_r0x00731449:
          return L"ERROR_DS_UNABLE_TO_SURRENDER_ROLES";
        case -0x7ff8df0c:
code_r0x00731453:
          return L"ERROR_DS_DRA_GENERIC";
        case -0x7ff8df0b:
code_r0x0073145d:
          return L"ERROR_DS_DRA_INVALID_PARAMETER";
        case -0x7ff8df0a:
code_r0x00731467:
          return L"ERROR_DS_DRA_BUSY";
        case -0x7ff8df09:
code_r0x00731471:
          return L"ERROR_DS_DRA_BAD_DN";
        case -0x7ff8df08:
code_r0x0073147b:
          return L"ERROR_DS_DRA_BAD_NC";
        case -0x7ff8df07:
code_r0x00731485:
          return L"ERROR_DS_DRA_DN_EXISTS";
        case -0x7ff8df06:
code_r0x0073148f:
          return L"ERROR_DS_DRA_INTERNAL_ERROR";
        case -0x7ff8df05:
code_r0x00731499:
          return L"ERROR_DS_DRA_INCONSISTENT_DIT";
        case -0x7ff8df04:
code_r0x007314a3:
          return L"ERROR_DS_DRA_CONNECTION_FAILED";
        case -0x7ff8df03:
code_r0x007314ad:
          return L"ERROR_DS_DRA_BAD_INSTANCE_TYPE";
        case -0x7ff8df02:
code_r0x007314b7:
          return L"ERROR_DS_DRA_OUT_OF_MEM";
        case -0x7ff8df01:
code_r0x007314c1:
          return L"ERROR_DS_DRA_MAIL_PROBLEM";
        case -0x7ff8df00:
code_r0x007314cb:
          return L"ERROR_DS_DRA_REF_ALREADY_EXISTS";
        case -0x7ff8deff:
code_r0x007314d5:
          return L"ERROR_DS_DRA_REF_NOT_FOUND";
        case -0x7ff8defe:
code_r0x007314df:
          return L"ERROR_DS_DRA_OBJ_IS_REP_SOURCE";
        case -0x7ff8defd:
code_r0x007314e9:
          return L"ERROR_DS_DRA_DB_ERROR";
        case -0x7ff8defc:
code_r0x007314f3:
          return L"ERROR_DS_DRA_NO_REPLICA";
        case -0x7ff8defb:
code_r0x007314fd:
          return L"ERROR_DS_DRA_ACCESS_DENIED";
        case -0x7ff8defa:
code_r0x00731507:
          return L"ERROR_DS_DRA_NOT_SUPPORTED";
        case -0x7ff8def9:
code_r0x00731511:
          return L"ERROR_DS_DRA_RPC_CANCELLED";
        case -0x7ff8def8:
code_r0x0073151b:
          return L"ERROR_DS_DRA_SOURCE_DISABLED";
        case -0x7ff8def7:
code_r0x00731525:
          return L"ERROR_DS_DRA_SINK_DISABLED";
        case -0x7ff8def6:
code_r0x0073152f:
          return L"ERROR_DS_DRA_NAME_COLLISION";
        case -0x7ff8def5:
code_r0x00731539:
          return L"ERROR_DS_DRA_SOURCE_REINSTALLED";
        case -0x7ff8def4:
code_r0x00731543:
          return L"ERROR_DS_DRA_MISSING_PARENT";
        case -0x7ff8def3:
code_r0x0073154d:
          return L"ERROR_DS_DRA_PREEMPTED";
        case -0x7ff8def2:
code_r0x00731557:
          return L"ERROR_DS_DRA_ABANDON_SYNC";
        case -0x7ff8def1:
code_r0x00731561:
          return L"ERROR_DS_DRA_SHUTDOWN";
        case -0x7ff8def0:
code_r0x0073156b:
          return L"ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET";
        case -0x7ff8deef:
code_r0x00731575:
          return L"ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA";
        case -0x7ff8deee:
code_r0x0073157f:
          return L"ERROR_DS_DRA_EXTN_CONNECTION_FAILED";
        case -0x7ff8deed:
code_r0x00731589:
          return L"ERROR_DS_INSTALL_SCHEMA_MISMATCH";
        case -0x7ff8deec:
code_r0x00731593:
          return L"ERROR_DS_DUP_LINK_ID";
        case -0x7ff8deeb:
code_r0x0073159d:
          return L"ERROR_DS_NAME_ERROR_RESOLVING";
        case -0x7ff8deea:
code_r0x007315a7:
          return L"ERROR_DS_NAME_ERROR_NOT_FOUND";
        case -0x7ff8dee9:
code_r0x007315b1:
          return L"ERROR_DS_NAME_ERROR_NOT_UNIQUE";
        case -0x7ff8dee8:
code_r0x007315bb:
          return L"ERROR_DS_NAME_ERROR_NO_MAPPING";
        case -0x7ff8dee7:
code_r0x007315c5:
          return L"ERROR_DS_NAME_ERROR_DOMAIN_ONLY";
        case -0x7ff8dee6:
code_r0x007315cf:
          return L"ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING";
        case -0x7ff8dee5:
code_r0x007315d9:
          return L"ERROR_DS_CONSTRUCTED_ATT_MOD";
        case -0x7ff8dee4:
code_r0x007315e3:
          return L"ERROR_DS_WRONG_OM_OBJ_CLASS";
        case -0x7ff8dee3:
code_r0x007315ed:
          return L"ERROR_DS_DRA_REPL_PENDING";
        case -0x7ff8dee2:
code_r0x007315f7:
          return L"ERROR_DS_DS_REQUIRED";
        case -0x7ff8dee1:
code_r0x00731601:
          return L"ERROR_DS_INVALID_LDAP_DISPLAY_NAME";
        case -0x7ff8dee0:
code_r0x0073160b:
          return L"ERROR_DS_NON_BASE_SEARCH";
        case -0x7ff8dedf:
code_r0x00731615:
          return L"ERROR_DS_CANT_RETRIEVE_ATTS";
        case -0x7ff8dede:
code_r0x0073161f:
          return L"ERROR_DS_BACKLINK_WITHOUT_LINK";
        case -0x7ff8dedd:
code_r0x00731629:
          return L"ERROR_DS_EPOCH_MISMATCH";
        case -0x7ff8dedc:
code_r0x00731633:
          return L"ERROR_DS_SRC_NAME_MISMATCH";
        case -0x7ff8dedb:
code_r0x0073163d:
          return L"ERROR_DS_SRC_AND_DST_NC_IDENTICAL";
        case -0x7ff8deda:
code_r0x00731647:
          return L"ERROR_DS_DST_NC_MISMATCH";
        case -0x7ff8ded9:
code_r0x00731651:
          return L"ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC";
        case -0x7ff8ded8:
code_r0x0073165b:
          return L"ERROR_DS_SRC_GUID_MISMATCH";
        case -0x7ff8ded7:
code_r0x00731665:
          return L"ERROR_DS_CANT_MOVE_DELETED_OBJECT";
        case -0x7ff8ded6:
code_r0x0073166f:
          return L"ERROR_DS_PDC_OPERATION_IN_PROGRESS";
        case -0x7ff8ded5:
code_r0x00731679:
          return L"ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD";
        case -0x7ff8ded4:
code_r0x00731683:
          return L"ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION";
        case -0x7ff8ded3:
code_r0x0073168d:
          return L"ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS";
        case -0x7ff8ded2:
code_r0x00731697:
          return L"ERROR_DS_NC_MUST_HAVE_NC_PARENT";
        case -0x7ff8ded1:
code_r0x007316a1:
          return L"ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE";
        case -0x7ff8ded0:
code_r0x007316ab:
          return L"ERROR_DS_DST_DOMAIN_NOT_NATIVE";
        case -0x7ff8decf:
code_r0x007316b5:
          return L"ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER";
        case -0x7ff8dece:
code_r0x007316bf:
          return L"ERROR_DS_CANT_MOVE_ACCOUNT_GROUP";
        case -0x7ff8decd:
code_r0x007316c9:
          return L"ERROR_DS_CANT_MOVE_RESOURCE_GROUP";
        case -0x7ff8decc:
code_r0x007316d3:
          return L"ERROR_DS_INVALID_SEARCH_FLAG";
        case -0x7ff8decb:
code_r0x007316dd:
          return L"ERROR_DS_NO_TREE_DELETE_ABOVE_NC";
        case -0x7ff8deca:
code_r0x007316e7:
          return L"ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE";
        case -0x7ff8dec9:
code_r0x007316f1:
          return L"ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE";
        case -0x7ff8dec8:
code_r0x007316fb:
          return L"ERROR_DS_SAM_INIT_FAILURE";
        case -0x7ff8dec7:
code_r0x00731705:
          return L"ERROR_DS_SENSITIVE_GROUP_VIOLATION";
        case -0x7ff8dec6:
code_r0x0073170f:
          return L"ERROR_DS_CANT_MOD_PRIMARYGROUPID";
        case -0x7ff8dec5:
code_r0x00731719:
          return L"ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD";
        case -0x7ff8dec4:
code_r0x00731723:
          return L"ERROR_DS_NONSAFE_SCHEMA_CHANGE";
        case -0x7ff8dec3:
code_r0x0073172d:
          return L"ERROR_DS_SCHEMA_UPDATE_DISALLOWED";
        case -0x7ff8dec2:
code_r0x00731737:
          return L"ERROR_DS_CANT_CREATE_UNDER_SCHEMA";
        case -0x7ff8dec1:
code_r0x00731741:
          return L"ERROR_DS_INSTALL_NO_SRC_SCH_VERSION";
        case -0x7ff8dec0:
code_r0x0073174b:
          return L"ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE";
        case -0x7ff8debf:
code_r0x00731755:
          return L"ERROR_DS_INVALID_GROUP_TYPE";
        case -0x7ff8debe:
code_r0x0073175f:
          return L"ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN";
        case -0x7ff8debd:
code_r0x00731769:
          return L"ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN";
        case -0x7ff8debc:
code_r0x00731773:
          return L"ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER";
        case -0x7ff8debb:
code_r0x0073177d:
          return L"ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER";
        case -0x7ff8deba:
code_r0x00731787:
          return L"ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER";
        case -0x7ff8deb9:
code_r0x00731791:
          return L"ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER";
        case -0x7ff8deb8:
code_r0x0073179b:
          return L"ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER";
        case -0x7ff8deb7:
code_r0x007317a5:
          return L"ERROR_DS_HAVE_PRIMARY_MEMBERS";
        case -0x7ff8deb6:
code_r0x007317af:
          return L"ERROR_DS_STRING_SD_CONVERSION_FAILED";
        case -0x7ff8deb5:
code_r0x007317b9:
          return L"ERROR_DS_NAMING_MASTER_GC";
        case -0x7ff8deb4:
code_r0x007317c3:
          return L"ERROR_DS_DNS_LOOKUP_FAILURE";
        case -0x7ff8deb3:
code_r0x007317cd:
          return L"ERROR_DS_COULDNT_UPDATE_SPNS";
        case -0x7ff8deb2:
code_r0x007317d7:
          return L"ERROR_DS_CANT_RETRIEVE_SD";
        case -0x7ff8deb1:
code_r0x007317e1:
          return L"ERROR_DS_KEY_NOT_UNIQUE";
        case -0x7ff8deb0:
code_r0x007317eb:
          return L"ERROR_DS_WRONG_LINKED_ATT_SYNTAX";
        case -0x7ff8deaf:
code_r0x007317f5:
          return L"ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD";
        case -0x7ff8deae:
code_r0x007317ff:
          return L"ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY";
        case -0x7ff8dead:
code_r0x00731809:
          return L"ERROR_DS_CANT_START";
        case -0x7ff8deac:
code_r0x00731813:
          return L"ERROR_DS_INIT_FAILURE";
        case -0x7ff8deab:
code_r0x0073181d:
          return L"ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION";
        case -0x7ff8deaa:
code_r0x00731827:
          return L"ERROR_DS_SOURCE_DOMAIN_IN_FOREST";
        case -0x7ff8dea9:
code_r0x00731831:
          return L"ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST";
        case -0x7ff8dea8:
code_r0x0073183b:
          return L"ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED";
        case -0x7ff8dea7:
code_r0x00731845:
          return L"ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN";
        case -0x7ff8dea6:
code_r0x0073184f:
          return L"ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER";
        case -0x7ff8dea5:
code_r0x00731859:
          return L"ERROR_DS_SRC_SID_EXISTS_IN_FOREST";
        case -0x7ff8dea4:
code_r0x00731863:
          return L"ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH";
        case -0x7ff8dea3:
code_r0x0073186d:
          return L"ERROR_SAM_INIT_FAILURE";
        case -0x7ff8dea2:
code_r0x00731877:
          return L"ERROR_DS_DRA_SCHEMA_INFO_SHIP";
        case -0x7ff8dea1:
code_r0x00731881:
          return L"ERROR_DS_DRA_SCHEMA_CONFLICT";
        case -0x7ff8dea0:
code_r0x0073188b:
          return L"ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT";
        case -0x7ff8de9f:
code_r0x00731895:
          return L"ERROR_DS_DRA_OBJ_NC_MISMATCH";
        case -0x7ff8de9e:
code_r0x0073189f:
          return L"ERROR_DS_NC_STILL_HAS_DSAS";
        case -0x7ff8de9d:
code_r0x007318a9:
          return L"ERROR_DS_GC_REQUIRED";
        case -0x7ff8de9c:
code_r0x007318b3:
          return L"ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY";
        case -0x7ff8de9b:
code_r0x007318bd:
          return L"ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS";
        case -0x7ff8de9a:
code_r0x007318c7:
          return L"ERROR_DS_CANT_ADD_TO_GC";
        case -0x7ff8de99:
code_r0x007318d1:
          return L"ERROR_DS_NO_CHECKPOINT_WITH_PDC";
        case -0x7ff8de98:
code_r0x007318db:
          return L"ERROR_DS_SOURCE_AUDITING_NOT_ENABLED";
        case -0x7ff8de97:
code_r0x007318e5:
          return L"ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC";
        case -0x7ff8de96:
code_r0x007318ef:
          return L"ERROR_DS_INVALID_NAME_FOR_SPN";
        case -0x7ff8de95:
code_r0x007318f9:
          return L"ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS";
        case -0x7ff8de94:
code_r0x00731903:
          return L"ERROR_DS_UNICODEPWD_NOT_IN_QUOTES";
        case -0x7ff8de93:
code_r0x0073190d:
          return L"ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED";
        case -0x7ff8de92:
code_r0x00731917:
          return L"ERROR_DS_MUST_BE_RUN_ON_DST_DC";
        case -0x7ff8de91:
code_r0x00731921:
          return L"ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER";
        case -0x7ff8de90:
code_r0x0073192b:
          return L"ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ";
        case -0x7ff8de8f:
code_r0x00731935:
          return L"ERROR_DS_INIT_FAILURE_CONSOLE";
        case -0x7ff8de8e:
code_r0x0073193f:
          return L"ERROR_DS_SAM_INIT_FAILURE_CONSOLE";
        case -0x7ff8de8d:
code_r0x00731949:
          return L"ERROR_DS_FOREST_VERSION_TOO_HIGH";
        case -0x7ff8de8c:
code_r0x00731953:
          return L"ERROR_DS_DOMAIN_VERSION_TOO_HIGH";
        case -0x7ff8de8b:
code_r0x0073195d:
          return L"ERROR_DS_FOREST_VERSION_TOO_LOW";
        case -0x7ff8de8a:
code_r0x00731967:
          return L"ERROR_DS_DOMAIN_VERSION_TOO_LOW";
        case -0x7ff8de89:
code_r0x00731971:
          return L"ERROR_DS_INCOMPATIBLE_VERSION";
        case -0x7ff8de88:
code_r0x0073197b:
          return L"ERROR_DS_LOW_DSA_VERSION";
        case -0x7ff8de87:
code_r0x00731985:
          return L"ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN";
        case -0x7ff8de86:
code_r0x0073198f:
          return L"ERROR_DS_NOT_SUPPORTED_SORT_ORDER";
        case -0x7ff8de85:
code_r0x00731999:
          return L"ERROR_DS_NAME_NOT_UNIQUE";
        }
      }
    }
    else if (param_1 < -0x7ff8dcd7) {
      if (param_1 == -0x7ff8dcd8) {
LAB_00731acf:
        return L"DNS_ERROR_RESPONSE_CODES_BASE";
      }
      switch(param_1) {
      case -0x7ff8de83:
code_r0x007319ad:
        return L"ERROR_DS_OUT_OF_VERSION_STORE";
      case -0x7ff8de82:
code_r0x007319b7:
        return L"ERROR_DS_INCOMPATIBLE_CONTROLS_USED";
      case -0x7ff8de81:
code_r0x007319c1:
        return L"ERROR_DS_NO_REF_DOMAIN";
      case -0x7ff8de80:
code_r0x007319cb:
        return L"ERROR_DS_RESERVED_LINK_ID";
      case -0x7ff8de7f:
code_r0x007319d5:
        return L"ERROR_DS_LINK_ID_NOT_AVAILABLE";
      case -0x7ff8de7e:
code_r0x007319df:
        return L"ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER";
      case -0x7ff8de7d:
code_r0x007319e9:
        return L"ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE";
      case -0x7ff8de7c:
code_r0x007319f3:
        return L"ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC";
      case -0x7ff8de7b:
code_r0x007319fd:
        return L"ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG";
      case -0x7ff8de7a:
code_r0x00731a07:
        return L"ERROR_DS_MODIFYDN_WRONG_GRANDPARENT";
      case -0x7ff8de79:
code_r0x00731a11:
        return L"ERROR_DS_NAME_ERROR_TRUST_REFERRAL";
      case -0x7ff8de78:
code_r0x00731a1b:
        return L"ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER";
      case -0x7ff8de77:
code_r0x00731a25:
        return L"ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD";
      case -0x7ff8de76:
code_r0x00731a2f:
        return L"ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2";
      case -0x7ff8de75:
code_r0x00731a39:
        return L"ERROR_DS_THREAD_LIMIT_EXCEEDED";
      case -0x7ff8de74:
code_r0x00731a43:
        return L"ERROR_DS_NOT_CLOSEST";
      case -0x7ff8de73:
code_r0x00731a4d:
        return L"ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF";
      case -0x7ff8de72:
code_r0x00731a57:
        return L"ERROR_DS_SINGLE_USER_MODE_FAILED";
      case -0x7ff8de71:
code_r0x00731a61:
        return L"ERROR_DS_NTDSCRIPT_SYNTAX_ERROR";
      case -0x7ff8de70:
code_r0x00731a6b:
        return L"ERROR_DS_NTDSCRIPT_PROCESS_ERROR";
      case -0x7ff8de6f:
code_r0x00731a75:
        return L"ERROR_DS_DIFFERENT_REPL_EPOCHS";
      case -0x7ff8de6e:
code_r0x00731a7f:
        return L"ERROR_DS_DRS_EXTENSIONS_CHANGED";
      case -0x7ff8de6d:
code_r0x00731a89:
        return L"ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR";
      case -0x7ff8de6c:
code_r0x00731a93:
        return L"ERROR_DS_NO_MSDS_INTID";
      case -0x7ff8de6b:
code_r0x00731a9d:
        return L"ERROR_DS_DUP_MSDS_INTID";
      case -0x7ff8de6a:
code_r0x00731aa7:
        return L"ERROR_DS_EXISTS_IN_RDNATTID";
      case -0x7ff8de69:
code_r0x00731ab1:
        return L"ERROR_DS_AUTHORIZATION_FAILED";
      case -0x7ff8de68:
code_r0x00731abb:
        return L"ERROR_DS_INVALID_SCRIPT";
      case -0x7ff8de67:
code_r0x00731ac5:
        return L"ERROR_DS_REMOTE_CROSSREF_OP_FAILED";
      }
    }
    else if (param_1 < -0x7ff8dae3) {
      if (param_1 == -0x7ff8dae4) {
LAB_00731b83:
        return L"DNS_ERROR_PACKET_FMT_BASE";
      }
      switch(param_1) {
      case -0x7ff8dcd7:
code_r0x00731b01:
        return L"DNS_ERROR_RCODE_FORMAT_ERROR";
      case -0x7ff8dcd6:
code_r0x00731b0b:
        return L"DNS_ERROR_RCODE_SERVER_FAILURE";
      case -0x7ff8dcd5:
code_r0x00731b15:
        return L"DNS_ERROR_RCODE_NAME_ERROR";
      case -0x7ff8dcd4:
code_r0x00731b1f:
        return L"DNS_ERROR_RCODE_NOT_IMPLEMENTED";
      case -0x7ff8dcd3:
code_r0x00731b29:
        return L"DNS_ERROR_RCODE_REFUSED";
      case -0x7ff8dcd2:
code_r0x00731b33:
        return L"DNS_ERROR_RCODE_YXDOMAIN";
      case -0x7ff8dcd1:
code_r0x00731b3d:
        return L"DNS_ERROR_RCODE_YXRRSET";
      case -0x7ff8dcd0:
code_r0x00731b47:
        return L"DNS_ERROR_RCODE_NXRRSET";
      case -0x7ff8dccf:
code_r0x00731b51:
        return L"DNS_ERROR_RCODE_NOTAUTH";
      case -0x7ff8dcce:
code_r0x00731b5b:
        return L"DNS_ERROR_RCODE_NOTZONE";
      case -0x7ff8dcc8:
code_r0x00731b65:
        return L"DNS_ERROR_RCODE_BADSIG";
      case -0x7ff8dcc7:
code_r0x00731b6f:
        return L"DNS_ERROR_RCODE_BADKEY";
      case -0x7ff8dcc6:
code_r0x00731b79:
        return L"DNS_ERROR_RCODE_BADTIME";
      }
    }
    else if (param_1 < -0x7ff8c944) {
      if (param_1 == -0x7ff8c945) {
LAB_007328d3:
        return L"ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET";
      }
      if (param_1 < -0x7ff8d4fc) {
        if (param_1 == -0x7ff8d4fd) {
LAB_00732256:
          return L"WSA_QOS_POLICY_FAILURE";
        }
        if (param_1 < -0x7ff8d8ef) {
          if (param_1 == -0x7ff8d8f0) {
LAB_00731f1c:
            return L"WSABASEERR";
          }
          if (param_1 < -0x7ff8da4d) {
            if (param_1 == -0x7ff8da4e) goto LAB_00731d38;
            switch(param_1) {
            case -0x7ff8dae3:
              goto code_r0x00731be4;
            case -0x7ff8dae2:
              goto code_r0x00731bee;
            case -0x7ff8dae1:
              goto code_r0x00731bf8;
            case -0x7ff8dae0:
              goto code_r0x00731c02;
            case -0x7ff8dadf:
              goto code_r0x00731c0c;
            case -0x7ff8dab2:
              goto code_r0x00731c16;
            case -0x7ff8dab1:
              goto code_r0x00731c20;
            case -0x7ff8dab0:
              goto code_r0x00731c2a;
            case -0x7ff8daaf:
              goto code_r0x00731c34;
            case -0x7ff8daae:
              goto code_r0x00731c3e;
            case -0x7ff8daad:
              goto code_r0x00731c48;
            case -0x7ff8daac:
              goto code_r0x00731c52;
            case -0x7ff8daab:
              goto code_r0x00731c5c;
            case -0x7ff8daaa:
              goto code_r0x00731c66;
            case -0x7ff8daa9:
              goto code_r0x00731c70;
            case -0x7ff8da80:
              goto code_r0x00731c7a;
            case -0x7ff8da7f:
              goto code_r0x00731c84;
            case -0x7ff8da7e:
              goto code_r0x00731c8e;
            case -0x7ff8da7d:
              goto code_r0x00731c98;
            case -0x7ff8da7c:
              goto code_r0x00731ca2;
            case -0x7ff8da7b:
              goto code_r0x00731cac;
            case -0x7ff8da7a:
              goto code_r0x00731cb6;
            case -0x7ff8da79:
              goto code_r0x00731cc0;
            case -0x7ff8da78:
              goto code_r0x00731cca;
            case -0x7ff8da77:
              goto code_r0x00731cd4;
            case -0x7ff8da76:
              goto code_r0x00731cde;
            case -0x7ff8da75:
              goto code_r0x00731ce8;
            case -0x7ff8da74:
              goto code_r0x00731cf2;
            case -0x7ff8da73:
              goto code_r0x00731cfc;
            case -0x7ff8da72:
              goto code_r0x00731d06;
            case -0x7ff8da71:
              goto code_r0x00731d10;
            case -0x7ff8da70:
              goto code_r0x00731d1a;
            case -0x7ff8da6f:
              goto code_r0x00731d24;
            case -0x7ff8da6e:
              goto code_r0x00731d2e;
            }
          }
          else if (param_1 < -0x7ff8da0f) {
            if (param_1 == -0x7ff8da10) goto LAB_00731dec;
            switch(param_1) {
            case -0x7ff8da4d:
              goto LAB_00731d42;
            case -0x7ff8da4c:
              goto LAB_00731d4c;
            case -0x7ff8da4b:
              goto LAB_00731d56;
            case -0x7ff8da4a:
              goto LAB_00731d60;
            case -0x7ff8da49:
              goto LAB_00731d6a;
            case -0x7ff8da1c:
              goto LAB_00731d74;
            case -0x7ff8da1b:
              goto LAB_00731d7e;
            case -0x7ff8da1a:
              goto LAB_00731d88;
            case -0x7ff8da19:
              goto LAB_00731d92;
            case -0x7ff8da18:
              goto LAB_00731d9c;
            case -0x7ff8da17:
              goto LAB_00731da6;
            case -0x7ff8da16:
              goto LAB_00731db0;
            case -0x7ff8da15:
              goto LAB_00731dba;
            case -0x7ff8da14:
              goto LAB_00731dc4;
            case -0x7ff8da13:
              goto LAB_00731dce;
            case -0x7ff8da12:
              goto LAB_00731dd8;
            case -0x7ff8da11:
              goto LAB_00731de2;
            }
          }
          else if (param_1 < -0x7ff8d9e8) {
            if (param_1 == -0x7ff8d9e9) {
LAB_00731eb8:
              return L"DNS_INFO_AXFR_COMPLETE";
            }
            if (param_1 < -0x7ff8da0a) {
              if (param_1 == -0x7ff8da0b) goto LAB_00731e14;
              if (param_1 == -0x7ff8da0f) goto LAB_00731df6;
              if (param_1 == -0x7ff8da0e) goto LAB_00731e00;
              if (param_1 == -0x7ff8da0d) goto LAB_00731e0a;
              if (param_1 == -0x7ff8da0c) goto code_r0x0072a3d0;
            }
            else {
              if (param_1 == -0x7ff8da0a) goto LAB_00731e1e;
              if (param_1 == -0x7ff8da09) goto LAB_00731e28;
              if (param_1 == -0x7ff8d9ea) goto LAB_0072a3fb;
            }
          }
          else {
            if (param_1 == -0x7ff8d9e8) {
LAB_00731eae:
              return L"DNS_ERROR_AXFR";
            }
            if (param_1 == -0x7ff8d9e7) {
LAB_00731ea4:
              return L"DNS_INFO_ADDED_LOCAL_WINS";
            }
            if (param_1 == -0x7ff8d9b8) {
LAB_00731e9a:
              return L"DNS_ERROR_SECURE_BASE";
            }
            if (param_1 == -0x7ff8d9b7) {
LAB_00731e90:
              return L"DNS_STATUS_CONTINUE_NEEDED";
            }
            if (param_1 == -0x7ff8d986) {
LAB_00731e86:
              return L"DNS_ERROR_SETUP_BASE";
            }
            if (param_1 == -0x7ff8d985) goto LAB_00731ec2;
            if (param_1 == -0x7ff8d984) goto LAB_0072a452;
          }
        }
        else if (param_1 < -0x7ff8d8b0) {
          if (param_1 == -0x7ff8d8b1) {
LAB_0073208a:
            return L"WSAENAMETOOLONG";
          }
          switch(param_1) {
          case -0x7ff8d8ec:
LAB_00731f12:
            return L"WSAEINTR";
          case -0x7ff8d8e7:
LAB_00731f08:
            return L"WSAEBADF";
          case -0x7ff8d8e3:
LAB_00731efe:
            return L"WSAEACCES";
          case -0x7ff8d8e2:
code_r0x00731ef4:
            return L"WSAEFAULT";
          case -0x7ff8d8da:
LAB_00731f26:
            return L"WSAEINVAL";
          case -0x7ff8d8d8:
code_r0x00731f4c:
            return L"WSAEMFILE";
          case -0x7ff8d8cd:
code_r0x00731f56:
            return L"WSAEWOULDBLOCK";
          case -0x7ff8d8cc:
code_r0x00731f60:
            return L"WSAEINPROGRESS";
          case -0x7ff8d8cb:
code_r0x00731f6a:
            return L"WSAEALREADY";
          case -0x7ff8d8ca:
code_r0x00731f74:
            return L"WSAENOTSOCK";
          case -0x7ff8d8c9:
code_r0x00731f7e:
            return L"WSAEDESTADDRREQ";
          case -0x7ff8d8c8:
code_r0x00731f88:
            return L"WSAEMSGSIZE";
          case -0x7ff8d8c7:
code_r0x00731f92:
            return L"WSAEPROTOTYPE";
          case -0x7ff8d8c6:
code_r0x00731f9c:
            return L"WSAENOPROTOOPT";
          case -0x7ff8d8c5:
code_r0x00731fa6:
            return L"WSAEPROTONOSUPPORT";
          case -0x7ff8d8c4:
code_r0x00731fb0:
            return L"WSAESOCKTNOSUPPORT";
          case -0x7ff8d8c3:
code_r0x00731fba:
            return L"WSAEOPNOTSUPP";
          case -0x7ff8d8c2:
code_r0x00731fc4:
            return L"WSAEPFNOSUPPORT";
          case -0x7ff8d8c1:
code_r0x00731fce:
            return L"WSAEAFNOSUPPORT";
          case -0x7ff8d8c0:
            goto LAB_00731fd8;
          case -0x7ff8d8bf:
            goto code_r0x00731ffe;
          case -0x7ff8d8be:
            goto code_r0x00732008;
          case -0x7ff8d8bd:
            goto code_r0x00732012;
          case -0x7ff8d8bc:
            goto code_r0x0073201c;
          case -0x7ff8d8bb:
            goto code_r0x00732026;
          case -0x7ff8d8ba:
            goto code_r0x00732030;
          case -0x7ff8d8b9:
            goto code_r0x0073203a;
          case -0x7ff8d8b8:
            goto code_r0x00732044;
          case -0x7ff8d8b7:
            goto code_r0x0073204e;
          case -0x7ff8d8b6:
            goto code_r0x00732058;
          case -0x7ff8d8b5:
            goto code_r0x00732062;
          case -0x7ff8d8b4:
            goto code_r0x0073206c;
          case -0x7ff8d8b3:
            goto code_r0x00732076;
          case -0x7ff8d8b2:
            goto code_r0x00732080;
          }
        }
        else if (param_1 < -0x7ff8d885) {
          if (param_1 == -0x7ff8d886) {
LAB_007321b5:
            return L"WSAEPROVIDERFAILEDINIT";
          }
          switch(param_1) {
          case -0x7ff8d8b0:
            goto LAB_00732094;
          case -0x7ff8d8af:
            goto LAB_0073209e;
          case -0x7ff8d8ae:
            goto LAB_007320a8;
          case -0x7ff8d8ad:
            goto LAB_007320b2;
          case -0x7ff8d8ac:
            goto LAB_007320bc;
          case -0x7ff8d8ab:
            goto LAB_007320c6;
          case -0x7ff8d8aa:
            goto LAB_007320d0;
          case -0x7ff8d8a9:
            goto LAB_007320da;
          case -0x7ff8d895:
            goto LAB_007320e4;
          case -0x7ff8d894:
            goto LAB_007320ee;
          case -0x7ff8d893:
            goto LAB_007320f8;
          case -0x7ff8d88b:
            goto LAB_00732102;
          case -0x7ff8d88a:
            goto LAB_0073210c;
          case -0x7ff8d889:
            goto LAB_00732116;
          case -0x7ff8d888:
            goto LAB_00732120;
          case -0x7ff8d887:
LAB_007321bf:
            return L"WSAEINVALIDPROVIDER";
          }
        }
        else if (param_1 < -0x7ff8d504) {
          if (param_1 == -0x7ff8d505) {
LAB_0073220f:
            return L"WSANO_RECOVERY";
          }
          if (param_1 < -0x7ff8d880) {
            if (param_1 == -0x7ff8d881) {
LAB_0073218d:
              return L"WSA_E_CANCELLED";
            }
            if (param_1 == -0x7ff8d885) {
LAB_007321ab:
              return L"WSASYSCALLFAILURE";
            }
            if (param_1 == -0x7ff8d884) {
LAB_007321a1:
              return L"WSASERVICE_NOT_FOUND";
            }
            if (param_1 == -0x7ff8d883) {
LAB_00732197:
              return L"WSATYPE_NOT_FOUND";
            }
            if (param_1 == -0x7ff8d882) {
LAB_0072a4fc:
              return L"WSA_E_NO_MORE";
            }
          }
          else {
            if (param_1 == -0x7ff8d880) {
LAB_007321c9:
              return L"WSAEREFUSED";
            }
            if (param_1 == -0x7ff8d507) goto LAB_00732219;
            if (param_1 == -0x7ff8d506) goto LAB_0072a527;
          }
        }
        else {
          if (param_1 == -0x7ff8d504) {
LAB_00732205:
            return L"WSANO_DATA";
          }
          if (param_1 == -0x7ff8d503) {
LAB_007321fb:
            return L"WSA_QOS_RECEIVERS";
          }
          if (param_1 == -0x7ff8d502) {
LAB_007321f1:
            return L"WSA_QOS_SENDERS";
          }
          if (param_1 == -0x7ff8d501) goto LAB_00732223;
          if (param_1 == -0x7ff8d500) goto LAB_00732242;
          if (param_1 == -0x7ff8d4ff) goto LAB_0073224c;
          if (param_1 == -0x7ff8d4fe) goto code_r0x0072a57e;
        }
      }
      else if (param_1 < -0x7ff8cd37) {
        if (param_1 == -0x7ff8cd38) {
LAB_00732348:
          return L"ERROR_IPSEC_QM_POLICY_EXISTS";
        }
        switch(param_1) {
        case -0x7ff8d4fc:
code_r0x00732260:
          return L"WSA_QOS_BAD_STYLE";
        case -0x7ff8d4fb:
code_r0x0073226a:
          return L"WSA_QOS_BAD_OBJECT";
        case -0x7ff8d4fa:
code_r0x00732274:
          return L"WSA_QOS_TRAFFIC_CTRL_ERROR";
        case -0x7ff8d4f9:
code_r0x0073227e:
          return L"WSA_QOS_GENERIC_ERROR";
        case -0x7ff8d4f8:
code_r0x00732288:
          return L"WSA_QOS_ESERVICETYPE";
        case -0x7ff8d4f7:
code_r0x00732292:
          return L"WSA_QOS_EFLOWSPEC";
        case -0x7ff8d4f6:
code_r0x0073229c:
          return L"WSA_QOS_EPROVSPECBUF";
        case -0x7ff8d4f5:
code_r0x007322a6:
          return L"WSA_QOS_EFILTERSTYLE";
        case -0x7ff8d4f4:
code_r0x007322b0:
          return L"WSA_QOS_EFILTERTYPE";
        case -0x7ff8d4f3:
code_r0x007322ba:
          return L"WSA_QOS_EFILTERCOUNT";
        case -0x7ff8d4f2:
LAB_007322c4:
          return L"WSA_QOS_EOBJLENGTH";
        case -0x7ff8d4f1:
code_r0x007322ee:
          return L"WSA_QOS_EFLOWCOUNT";
        case -0x7ff8d4f0:
code_r0x007322f8:
          return L"WSA_QOS_EUNKOWNPSOBJ";
        case -0x7ff8d4ef:
code_r0x00732302:
          return L"WSA_QOS_EPOLICYOBJ";
        case -0x7ff8d4ee:
code_r0x0073230c:
          return L"WSA_QOS_EFLOWDESC";
        case -0x7ff8d4ed:
code_r0x00732316:
          return L"WSA_QOS_EPSFLOWSPEC";
        case -0x7ff8d4ec:
code_r0x00732320:
          return L"WSA_QOS_EPSFILTERSPEC";
        case -0x7ff8d4eb:
code_r0x0073232a:
          return L"WSA_QOS_ESDMODEOBJ";
        case -0x7ff8d4ea:
code_r0x00732334:
          return L"WSA_QOS_ESHAPERATEOBJ";
        case -0x7ff8d4e9:
code_r0x0073233e:
          return L"WSA_QOS_RESERVED_PETYPE";
        }
      }
      else if (param_1 < -0x7ff8ca17) {
        if (param_1 == -0x7ff8ca18) {
LAB_0073249d:
          return L"ERROR_IPSEC_IKE_NEG_STATUS_BEGIN";
        }
        switch(param_1) {
        case -0x7ff8cd37:
code_r0x00732367:
          return L"ERROR_IPSEC_QM_POLICY_NOT_FOUND";
        case -0x7ff8cd36:
code_r0x00732371:
          return L"ERROR_IPSEC_QM_POLICY_IN_USE";
        case -0x7ff8cd35:
code_r0x0073237b:
          return L"ERROR_IPSEC_MM_POLICY_EXISTS";
        case -0x7ff8cd34:
code_r0x00732385:
          return L"ERROR_IPSEC_MM_POLICY_NOT_FOUND";
        case -0x7ff8cd33:
code_r0x0073238f:
          return L"ERROR_IPSEC_MM_POLICY_IN_USE";
        case -0x7ff8cd32:
code_r0x00732399:
          return L"ERROR_IPSEC_MM_FILTER_EXISTS";
        case -0x7ff8cd31:
code_r0x007323a3:
          return L"ERROR_IPSEC_MM_FILTER_NOT_FOUND";
        case -0x7ff8cd30:
code_r0x007323ad:
          return L"ERROR_IPSEC_TRANSPORT_FILTER_EXISTS";
        case -0x7ff8cd2f:
code_r0x007323b7:
          return L"ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND";
        case -0x7ff8cd2e:
code_r0x007323c1:
          return L"ERROR_IPSEC_MM_AUTH_EXISTS";
        case -0x7ff8cd2d:
code_r0x007323cb:
          return L"ERROR_IPSEC_MM_AUTH_NOT_FOUND";
        case -0x7ff8cd2c:
code_r0x007323d5:
          return L"ERROR_IPSEC_MM_AUTH_IN_USE";
        case -0x7ff8cd2b:
code_r0x007323df:
          return L"ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND";
        case -0x7ff8cd2a:
code_r0x007323e9:
          return L"ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND";
        case -0x7ff8cd29:
code_r0x007323f3:
          return L"ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND";
        case -0x7ff8cd28:
code_r0x007323fd:
          return L"ERROR_IPSEC_TUNNEL_FILTER_EXISTS";
        case -0x7ff8cd27:
code_r0x00732407:
          return L"ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND";
        case -0x7ff8cd26:
code_r0x00732411:
          return L"ERROR_IPSEC_MM_FILTER_PENDING_DELETION";
        case -0x7ff8cd25:
code_r0x0073241b:
          return L"ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION";
        case -0x7ff8cd24:
          goto LAB_00732425;
        case -0x7ff8cd23:
LAB_007324bb:
          return L"ERROR_IPSEC_MM_POLICY_PENDING_DELETION";
        case -0x7ff8cd22:
LAB_007324b1:
          return L"ERROR_IPSEC_MM_AUTH_PENDING_DELETION";
        case -0x7ff8cd21:
LAB_007324a7:
          return L"ERROR_IPSEC_QM_POLICY_PENDING_DELETION";
        }
      }
      else {
        switch(param_1) {
        case -0x7ff8ca17:
LAB_00732493:
          return L"ERROR_IPSEC_IKE_AUTH_FAIL";
        case -0x7ff8ca16:
LAB_00732489:
          return L"ERROR_IPSEC_IKE_ATTRIB_FAIL";
        case -0x7ff8ca15:
code_r0x0073247f:
          return L"ERROR_IPSEC_IKE_NEGOTIATION_PENDING";
        case -0x7ff8ca14:
LAB_007324c5:
          return L"ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR";
        case -0x7ff8ca13:
LAB_0073251b:
          return L"ERROR_IPSEC_IKE_TIMED_OUT";
        case -0x7ff8ca12:
LAB_00732511:
          return L"ERROR_IPSEC_IKE_NO_CERT";
        case -0x7ff8ca11:
LAB_00732507:
          return L"ERROR_IPSEC_IKE_SA_DELETED";
        case -0x7ff8ca10:
LAB_007324fd:
          return L"ERROR_IPSEC_IKE_SA_REAPED";
        case -0x7ff8ca0f:
LAB_007324f3:
          return L"ERROR_IPSEC_IKE_MM_ACQUIRE_DROP";
        case -0x7ff8ca0e:
code_r0x007324e9:
          return L"ERROR_IPSEC_IKE_QM_ACQUIRE_DROP";
        case -0x7ff8ca0d:
LAB_00732525:
          return L"ERROR_IPSEC_IKE_QUEUE_DROP_MM";
        case -0x7ff8ca0c:
code_r0x00732544:
          return L"ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM";
        case -0x7ff8ca0b:
code_r0x0073254e:
          return L"ERROR_IPSEC_IKE_DROP_NO_RESPONSE";
        case -0x7ff8ca0a:
code_r0x00732558:
          return L"ERROR_IPSEC_IKE_MM_DELAY_DROP";
        case -0x7ff8ca09:
code_r0x00732562:
          return L"ERROR_IPSEC_IKE_QM_DELAY_DROP";
        case -0x7ff8ca08:
code_r0x0073256c:
          return L"ERROR_IPSEC_IKE_ERROR";
        case -0x7ff8ca07:
code_r0x00732576:
          return L"ERROR_IPSEC_IKE_CRL_FAILED";
        case -0x7ff8ca06:
code_r0x00732580:
          return L"ERROR_IPSEC_IKE_INVALID_KEY_USAGE";
        case -0x7ff8ca05:
code_r0x0073258a:
          return L"ERROR_IPSEC_IKE_INVALID_CERT_TYPE";
        case -0x7ff8ca04:
code_r0x00732594:
          return L"ERROR_IPSEC_IKE_NO_PRIVATE_KEY";
        case -0x7ff8ca02:
code_r0x0073259e:
          return L"ERROR_IPSEC_IKE_DH_FAIL";
        case -0x7ff8ca00:
code_r0x007325a8:
          return L"ERROR_IPSEC_IKE_INVALID_HEADER";
        case -0x7ff8c9ff:
code_r0x007325b2:
          return L"ERROR_IPSEC_IKE_NO_POLICY";
        case -0x7ff8c9fe:
code_r0x007325bc:
          return L"ERROR_IPSEC_IKE_INVALID_SIGNATURE";
        case -0x7ff8c9fd:
code_r0x007325c6:
          return L"ERROR_IPSEC_IKE_KERBEROS_ERROR";
        case -0x7ff8c9fc:
LAB_007325d0:
          return L"ERROR_IPSEC_IKE_NO_PUBLIC_KEY";
        case -0x7ff8c9fb:
code_r0x007325ef:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR";
        case -0x7ff8c9fa:
code_r0x007325f9:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_SA";
        case -0x7ff8c9f9:
code_r0x00732603:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_PROP";
        case -0x7ff8c9f8:
code_r0x0073260d:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_TRANS";
        case -0x7ff8c9f7:
code_r0x00732617:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_KE";
        case -0x7ff8c9f6:
code_r0x00732621:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_ID";
        case -0x7ff8c9f5:
code_r0x0073262b:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_CERT";
        case -0x7ff8c9f4:
code_r0x00732635:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ";
        case -0x7ff8c9f3:
code_r0x0073263f:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_HASH";
        case -0x7ff8c9f2:
code_r0x00732649:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_SIG";
        case -0x7ff8c9f1:
code_r0x00732653:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_NONCE";
        case -0x7ff8c9f0:
code_r0x0073265d:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY";
        case -0x7ff8c9ef:
code_r0x00732667:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_DELETE";
        case -0x7ff8c9ee:
code_r0x00732671:
          return L"ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR";
        case -0x7ff8c9ed:
code_r0x0073267b:
          return L"ERROR_IPSEC_IKE_INVALID_PAYLOAD";
        case -0x7ff8c9ec:
code_r0x00732685:
          return L"ERROR_IPSEC_IKE_LOAD_SOFT_SA";
        case -0x7ff8c9eb:
code_r0x0073268f:
          return L"ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN";
        case -0x7ff8c9ea:
code_r0x00732699:
          return L"ERROR_IPSEC_IKE_INVALID_COOKIE";
        case -0x7ff8c9e9:
code_r0x007326a3:
          return L"ERROR_IPSEC_IKE_NO_PEER_CERT";
        case -0x7ff8c9e8:
code_r0x007326ad:
          return L"ERROR_IPSEC_IKE_PEER_CRL_FAILED";
        case -0x7ff8c9e7:
code_r0x007326b7:
          return L"ERROR_IPSEC_IKE_POLICY_CHANGE";
        case -0x7ff8c9e6:
code_r0x007326c1:
          return L"ERROR_IPSEC_IKE_NO_MM_POLICY";
        case -0x7ff8c9e5:
code_r0x007326cb:
          return L"ERROR_IPSEC_IKE_NOTCBPRIV";
        case -0x7ff8c9e4:
code_r0x007326d5:
          return L"ERROR_IPSEC_IKE_SECLOADFAIL";
        case -0x7ff8c9e3:
code_r0x007326df:
          return L"ERROR_IPSEC_IKE_FAILSSPINIT";
        case -0x7ff8c9e2:
code_r0x007326e9:
          return L"ERROR_IPSEC_IKE_FAILQUERYSSP";
        case -0x7ff8c9e1:
code_r0x007326f3:
          return L"ERROR_IPSEC_IKE_SRVACQFAIL";
        case -0x7ff8c9e0:
code_r0x007326fd:
          return L"ERROR_IPSEC_IKE_SRVQUERYCRED";
        case -0x7ff8c9df:
          goto LAB_00732707;
        case -0x7ff8c9de:
          goto code_r0x00732739;
        case -0x7ff8c9dd:
          goto code_r0x00732743;
        case -0x7ff8c9dc:
          goto code_r0x0073274d;
        case -0x7ff8c9db:
          goto code_r0x00732757;
        case -0x7ff8c9da:
          goto code_r0x00732761;
        case -0x7ff8c9d9:
          goto code_r0x0073276b;
        case -0x7ff8c9d8:
          goto code_r0x00732775;
        case -0x7ff8c9d7:
          goto code_r0x0073277f;
        case -0x7ff8c9d6:
          goto code_r0x00732789;
        case -0x7ff8c9d5:
          goto code_r0x00732793;
        case -0x7ff8c9d4:
          goto code_r0x0073279d;
        case -0x7ff8c9d3:
          goto code_r0x007327a7;
        case -0x7ff8c9d2:
          goto code_r0x007327b1;
        case -0x7ff8c9d1:
          goto code_r0x007327bb;
        case -0x7ff8c9d0:
          goto code_r0x007327c5;
        case -0x7ff8c9cf:
          goto code_r0x007327cf;
        case -0x7ff8c9ce:
          goto code_r0x007327d9;
        case -0x7ff8c9cd:
          goto code_r0x007327e3;
        case -0x7ff8c9cc:
          goto code_r0x007327ed;
        case -0x7ff8c9cb:
          goto code_r0x007327f7;
        case -0x7ff8c9ca:
          goto code_r0x00732801;
        case -0x7ff8c9c9:
          goto code_r0x0073280b;
        case -0x7ff8c9c7:
          goto code_r0x00732815;
        case -0x7ff8c9c6:
          goto code_r0x0073281f;
        case -0x7ff8c9c5:
          goto code_r0x00732829;
        case -0x7ff8c9c4:
          goto code_r0x00732833;
        case -0x7ff8c950:
          goto LAB_0073283d;
        case -0x7ff8c94f:
          goto LAB_0073286f;
        case -0x7ff8c94e:
          goto code_r0x00732879;
        case -0x7ff8c94d:
          goto code_r0x00732883;
        case -0x7ff8c94c:
          goto code_r0x0073288d;
        case -0x7ff8c94b:
          goto code_r0x00732897;
        case -0x7ff8c94a:
          goto code_r0x007328a1;
        case -0x7ff8c949:
          goto code_r0x007328ab;
        case -0x7ff8c948:
          goto code_r0x007328b5;
        case -0x7ff8c947:
          goto code_r0x007328bf;
        case -0x7ff8c946:
          goto code_r0x007328c9;
        }
      }
    }
    else if (param_1 < -0x7ff7fffe) {
      if (param_1 == -0x7ff7ffff) {
        return L"CO_E_CLASS_CREATE_FAILED";
      }
      switch(param_1) {
      case -0x7ff8c944:
LAB_007328dd:
        return L"ERROR_SXS_UNKNOWN_ENCODING_GROUP";
      case -0x7ff8c943:
LAB_007328e7:
        return L"ERROR_SXS_UNKNOWN_ENCODING";
      case -0x7ff8c942:
LAB_007328f1:
        return L"ERROR_SXS_INVALID_XML_NAMESPACE_URI";
      case -0x7ff8c941:
LAB_007328fb:
        return L"ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED";
      case -0x7ff8c940:
LAB_00732905:
        return L"ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED";
      case -0x7ff8c93f:
LAB_0073290f:
        return L"ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE";
      case -0x7ff8c93e:
LAB_00732919:
        return L"ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE";
      case -0x7ff8c93d:
LAB_00732923:
        return L"ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE";
      case -0x7ff8c93c:
LAB_0073292d:
        return L"ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT";
      case -0x7ff8c93b:
LAB_00732937:
        return L"ERROR_SXS_DUPLICATE_DLL_NAME";
      case -0x7ff8c93a:
LAB_00732941:
        return L"ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME";
      case -0x7ff8c939:
LAB_0073294b:
        return L"ERROR_SXS_DUPLICATE_CLSID";
      case -0x7ff8c938:
LAB_00732955:
        return L"ERROR_SXS_DUPLICATE_IID";
      case -0x7ff8c937:
LAB_0073295f:
        return L"ERROR_SXS_DUPLICATE_TLBID";
      case -0x7ff8c936:
LAB_00732969:
        return L"ERROR_SXS_DUPLICATE_PROGID";
      case -0x7ff8c935:
LAB_00732973:
        return L"ERROR_SXS_DUPLICATE_ASSEMBLY_NAME";
      case -0x7ff8c934:
LAB_0073297d:
        return L"ERROR_SXS_FILE_HASH_MISMATCH";
      case -0x7ff8c933:
LAB_00732987:
        return L"ERROR_SXS_POLICY_PARSE_ERROR";
      case -0x7ff8c932:
LAB_00732991:
        return L"ERROR_SXS_XML_E_MISSINGQUOTE";
      case -0x7ff8c931:
LAB_0073299b:
        return L"ERROR_SXS_XML_E_COMMENTSYNTAX";
      case -0x7ff8c930:
LAB_007329a5:
        return L"ERROR_SXS_XML_E_BADSTARTNAMECHAR";
      case -0x7ff8c92f:
LAB_007329af:
        return L"ERROR_SXS_XML_E_BADNAMECHAR";
      case -0x7ff8c92e:
LAB_007329b9:
        return L"ERROR_SXS_XML_E_BADCHARINSTRING";
      case -0x7ff8c92d:
LAB_007329c3:
        return L"ERROR_SXS_XML_E_XMLDECLSYNTAX";
      case -0x7ff8c92c:
LAB_007329cd:
        return L"ERROR_SXS_XML_E_BADCHARDATA";
      case -0x7ff8c92b:
LAB_007329d7:
        return L"ERROR_SXS_XML_E_MISSINGWHITESPACE";
      case -0x7ff8c92a:
LAB_007329e1:
        return L"ERROR_SXS_XML_E_EXPECTINGTAGEND";
      case -0x7ff8c929:
LAB_007329eb:
        return L"ERROR_SXS_XML_E_MISSINGSEMICOLON";
      case -0x7ff8c928:
LAB_007329f5:
        return L"ERROR_SXS_XML_E_UNBALANCEDPAREN";
      case -0x7ff8c927:
LAB_007329ff:
        return L"ERROR_SXS_XML_E_INTERNALERROR";
      case -0x7ff8c926:
LAB_00732a09:
        return L"ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE";
      case -0x7ff8c925:
LAB_00732a13:
        return L"ERROR_SXS_XML_E_INCOMPLETE_ENCODING";
      case -0x7ff8c924:
LAB_00732a1d:
        return L"ERROR_SXS_XML_E_MISSING_PAREN";
      case -0x7ff8c923:
LAB_00732a27:
        return L"ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE";
      case -0x7ff8c922:
LAB_00732a31:
        return L"ERROR_SXS_XML_E_MULTIPLE_COLONS";
      case -0x7ff8c921:
LAB_00732a3b:
        return L"ERROR_SXS_XML_E_INVALID_DECIMAL";
      case -0x7ff8c920:
LAB_00732a45:
        return L"ERROR_SXS_XML_E_INVALID_HEXIDECIMAL";
      case -0x7ff8c91f:
LAB_00732a4f:
        return L"ERROR_SXS_XML_E_INVALID_UNICODE";
      case -0x7ff8c91e:
LAB_00732a59:
        return L"ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK";
      case -0x7ff8c91d:
LAB_00732a63:
        return L"ERROR_SXS_XML_E_UNEXPECTEDENDTAG";
      case -0x7ff8c91c:
LAB_00732a6d:
        return L"ERROR_SXS_XML_E_UNCLOSEDTAG";
      case -0x7ff8c91b:
LAB_00732a77:
        return L"ERROR_SXS_XML_E_DUPLICATEATTRIBUTE";
      case -0x7ff8c91a:
LAB_00732a81:
        return L"ERROR_SXS_XML_E_MULTIPLEROOTS";
      case -0x7ff8c919:
LAB_00732a8b:
        return L"ERROR_SXS_XML_E_INVALIDATROOTLEVEL";
      case -0x7ff8c918:
LAB_00732a95:
        return L"ERROR_SXS_XML_E_BADXMLDECL";
      case -0x7ff8c917:
LAB_00732a9f:
        return L"ERROR_SXS_XML_E_MISSINGROOT";
      case -0x7ff8c916:
LAB_00732aa9:
        return L"ERROR_SXS_XML_E_UNEXPECTEDEOF";
      case -0x7ff8c915:
LAB_00732ab3:
        return L"ERROR_SXS_XML_E_BADPEREFINSUBSET";
      case -0x7ff8c914:
LAB_00732abd:
        return L"ERROR_SXS_XML_E_UNCLOSEDSTARTTAG";
      case -0x7ff8c913:
LAB_00732ac7:
        return L"ERROR_SXS_XML_E_UNCLOSEDENDTAG";
      case -0x7ff8c912:
LAB_00732ad1:
        return L"ERROR_SXS_XML_E_UNCLOSEDSTRING";
      case -0x7ff8c911:
LAB_00732adb:
        return L"ERROR_SXS_XML_E_UNCLOSEDCOMMENT";
      case -0x7ff8c910:
LAB_00732ae5:
        return L"ERROR_SXS_XML_E_UNCLOSEDDECL";
      case -0x7ff8c90f:
LAB_00732aef:
        return L"ERROR_SXS_XML_E_UNCLOSEDCDATA";
      case -0x7ff8c90e:
LAB_00732af9:
        return L"ERROR_SXS_XML_E_RESERVEDNAMESPACE";
      case -0x7ff8c90d:
LAB_00732b03:
        return L"ERROR_SXS_XML_E_INVALIDENCODING";
      case -0x7ff8c90c:
LAB_00732b0d:
        return L"ERROR_SXS_XML_E_INVALIDSWITCH";
      case -0x7ff8c90b:
LAB_00732b17:
        return L"ERROR_SXS_XML_E_BADXMLCASE";
      case -0x7ff8c90a:
LAB_00732b21:
        return L"ERROR_SXS_XML_E_INVALID_STANDALONE";
      case -0x7ff8c909:
LAB_00732b2b:
        return L"ERROR_SXS_XML_E_UNEXPECTED_STANDALONE";
      case -0x7ff8c908:
LAB_00732b35:
        return L"ERROR_SXS_XML_E_INVALID_VERSION";
      case -0x7ff8c907:
LAB_00732b3f:
        return L"ERROR_SXS_XML_E_MISSINGEQUALS";
      case -0x7ff8c906:
LAB_00732b49:
        return L"ERROR_SXS_PROTECTION_RECOVERY_FAILED";
      case -0x7ff8c905:
LAB_00732b53:
        return L"ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT";
      case -0x7ff8c904:
LAB_00732b5d:
        return L"ERROR_SXS_PROTECTION_CATALOG_NOT_VALID";
      case -0x7ff8c903:
LAB_00732b67:
        return L"ERROR_SXS_UNTRANSLATABLE_HRESULT";
      case -0x7ff8c902:
LAB_00732b71:
        return L"ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING";
      case -0x7ff8c901:
LAB_00732b7b:
        return L"ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE";
      case -0x7ff8c900:
LAB_00732b85:
        return L"ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME";
      }
    }
    else if (param_1 < -0x7ff6fffe) {
      if (param_1 == -0x7ff6ffff) {
        return L"NTE_BAD_UID";
      }
      switch(param_1) {
      case -0x7ff7fffe:
        return L"CO_E_SCM_ERROR";
      case -0x7ff7fffd:
        return L"CO_E_SCM_RPC_FAILURE";
      case -0x7ff7fffc:
        return L"CO_E_BAD_PATH";
      case -0x7ff7fffb:
        return L"CO_E_SERVER_EXEC_FAILURE";
      case -0x7ff7fffa:
        return L"CO_E_OBJSRV_RPC_FAILURE";
      case -0x7ff7fff9:
        return L"MK_E_NO_NORMALIZED";
      case -0x7ff7fff8:
        return L"CO_E_SERVER_STOPPING";
      case -0x7ff7fff7:
        return L"MEM_E_INVALID_ROOT";
      case -0x7ff7fff0:
        return L"MEM_E_INVALID_LINK";
      case -0x7ff7ffef:
        return L"MEM_E_INVALID_SIZE";
      }
    }
    else if (param_1 < -0x7ff6fcff) {
      if (param_1 == -0x7ff6fd00) {
        return L"SEC_E_INSUFFICIENT_MEMORY";
      }
      switch(param_1) {
      case -0x7ff6fffe:
        return L"NTE_BAD_HASH";
      case -0x7ff6fffd:
        return L"NTE_BAD_KEY";
      case -0x7ff6fffc:
        return L"NTE_BAD_LEN";
      case -0x7ff6fffb:
        return L"NTE_BAD_DATA";
      case -0x7ff6fffa:
        return L"NTE_BAD_SIGNATURE";
      case -0x7ff6fff9:
        return L"NTE_BAD_VER";
      case -0x7ff6fff8:
        return L"NTE_BAD_ALGID";
      case -0x7ff6fff7:
        return L"NTE_BAD_FLAGS";
      case -0x7ff6fff6:
        return L"NTE_BAD_TYPE";
      case -0x7ff6fff5:
        return L"NTE_BAD_KEY_STATE";
      case -0x7ff6fff4:
        return L"NTE_BAD_HASH_STATE";
      case -0x7ff6fff3:
        return L"NTE_NO_KEY";
      case -0x7ff6fff2:
        return L"NTE_NO_MEMORY";
      case -0x7ff6fff1:
        return L"NTE_EXISTS";
      case -0x7ff6fff0:
        return L"NTE_PERM";
      case -0x7ff6ffef:
        return L"NTE_NOT_FOUND";
      case -0x7ff6ffee:
        return L"NTE_DOUBLE_ENCRYPT";
      case -0x7ff6ffed:
        return L"NTE_BAD_PROVIDER";
      case -0x7ff6ffec:
        return L"NTE_BAD_PROV_TYPE";
      case -0x7ff6ffeb:
        return L"NTE_BAD_PUBLIC_KEY";
      case -0x7ff6ffea:
        return L"NTE_BAD_KEYSET";
      case -0x7ff6ffe9:
        return L"NTE_PROV_TYPE_NOT_DEF";
      case -0x7ff6ffe8:
        return L"NTE_PROV_TYPE_ENTRY_BAD";
      case -0x7ff6ffe7:
        return L"NTE_KEYSET_NOT_DEF";
      case -0x7ff6ffe6:
        return L"NTE_KEYSET_ENTRY_BAD";
      case -0x7ff6ffe5:
        return L"NTE_PROV_TYPE_NO_MATCH";
      case -0x7ff6ffe4:
        return L"NTE_SIGNATURE_FILE_BAD";
      case -0x7ff6ffe3:
        return L"NTE_PROVIDER_DLL_FAIL";
      case -0x7ff6ffe2:
        return L"NTE_PROV_DLL_NOT_FOUND";
      case -0x7ff6ffe1:
        return L"NTE_BAD_KEYSET_PARAM";
      case -0x7ff6ffe0:
        return L"NTE_FAIL";
      case -0x7ff6ffdf:
        return L"NTE_SYS_ERR";
      case -0x7ff6ffde:
        return L"NTE_SILENT_CONTEXT";
      case -0x7ff6ffdd:
        return L"NTE_TOKEN_KEYSET_STORAGE_FULL";
      case -0x7ff6ffdc:
        return L"NTE_TEMPORARY_PROFILE";
      case -0x7ff6ffdb:
        return L"NTE_FIXEDPARAMETER";
      }
    }
    else if (param_1 < -0x7ff6effe) {
      if (param_1 == -0x7ff6efff) {
        return L"CRYPT_E_MSG_ERROR";
      }
      switch(param_1) {
      case -0x7ff6fcff:
        return L"SEC_E_INVALID_HANDLE";
      case -0x7ff6fcfe:
        return L"SEC_E_UNSUPPORTED_FUNCTION";
      case -0x7ff6fcfd:
        return L"SEC_E_TARGET_UNKNOWN";
      case -0x7ff6fcfc:
        return L"SEC_E_INTERNAL_ERROR";
      case -0x7ff6fcfb:
        return L"SEC_E_SECPKG_NOT_FOUND";
      case -0x7ff6fcfa:
        return L"SEC_E_NOT_OWNER";
      case -0x7ff6fcf9:
        return L"SEC_E_CANNOT_INSTALL";
      case -0x7ff6fcf8:
        return L"SEC_E_INVALID_TOKEN";
      case -0x7ff6fcf7:
        return L"SEC_E_CANNOT_PACK";
      case -0x7ff6fcf6:
        return L"SEC_E_QOP_NOT_SUPPORTED";
      case -0x7ff6fcf5:
        return L"SEC_E_NO_IMPERSONATION";
      case -0x7ff6fcf4:
        return L"SEC_E_LOGON_DENIED";
      case -0x7ff6fcf3:
        return L"SEC_E_UNKNOWN_CREDENTIALS";
      case -0x7ff6fcf2:
        return L"SEC_E_NO_CREDENTIALS";
      case -0x7ff6fcf1:
        return L"SEC_E_MESSAGE_ALTERED";
      case -0x7ff6fcf0:
        return L"SEC_E_OUT_OF_SEQUENCE";
      case -0x7ff6fcef:
        return L"SEC_E_NO_AUTHENTICATING_AUTHORITY";
      case -0x7ff6fcea:
        return L"SEC_E_BAD_PKGID";
      case -0x7ff6fce9:
        return L"SEC_E_CONTEXT_EXPIRED";
      case -0x7ff6fce8:
        return L"SEC_E_INCOMPLETE_MESSAGE";
      case -0x7ff6fce0:
        return L"SEC_E_INCOMPLETE_CREDENTIALS";
      case -0x7ff6fcdf:
        return L"SEC_E_BUFFER_TOO_SMALL";
      case -0x7ff6fcde:
        return L"SEC_E_WRONG_PRINCIPAL";
      case -0x7ff6fcdc:
        return L"SEC_E_TIME_SKEW";
      case -0x7ff6fcdb:
        return L"SEC_E_UNTRUSTED_ROOT";
      case -0x7ff6fcda:
        return L"SEC_E_ILLEGAL_MESSAGE";
      case -0x7ff6fcd9:
        return L"SEC_E_CERT_UNKNOWN";
      case -0x7ff6fcd8:
        return L"SEC_E_CERT_EXPIRED";
      case -0x7ff6fcd7:
        return L"SEC_E_ENCRYPT_FAILURE";
      case -0x7ff6fcd0:
        return L"SEC_E_DECRYPT_FAILURE";
      case -0x7ff6fccf:
        return L"SEC_E_ALGORITHM_MISMATCH";
      case -0x7ff6fcce:
        return L"SEC_E_SECURITY_QOS_FAILED";
      case -0x7ff6fccd:
        return L"SEC_E_UNFINISHED_CONTEXT_DELETED";
      case -0x7ff6fccc:
        return L"SEC_E_NO_TGT_REPLY";
      case -0x7ff6fccb:
        return L"SEC_E_NO_IP_ADDRESSES";
      case -0x7ff6fcca:
        return L"SEC_E_WRONG_CREDENTIAL_HANDLE";
      case -0x7ff6fcc9:
        return L"SEC_E_CRYPTO_SYSTEM_INVALID";
      case -0x7ff6fcc8:
        return L"SEC_E_MAX_REFERRALS_EXCEEDED";
      case -0x7ff6fcc7:
        return L"SEC_E_MUST_BE_KDC";
      case -0x7ff6fcc6:
        return L"SEC_E_STRONG_CRYPTO_NOT_SUPPORTED";
      case -0x7ff6fcc5:
        return L"SEC_E_TOO_MANY_PRINCIPALS";
      case -0x7ff6fcc4:
        return L"SEC_E_NO_PA_DATA";
      case -0x7ff6fcc3:
        return L"SEC_E_PKINIT_NAME_MISMATCH";
      case -0x7ff6fcc2:
        return L"SEC_E_SMARTCARD_LOGON_REQUIRED";
      case -0x7ff6fcc1:
        return L"SEC_E_SHUTDOWN_IN_PROGRESS";
      case -0x7ff6fcc0:
        return L"SEC_E_KDC_INVALID_REQUEST";
      case -0x7ff6fcbf:
        return L"SEC_E_KDC_UNABLE_TO_REFER";
      case -0x7ff6fcbe:
        return L"SEC_E_KDC_UNKNOWN_ETYPE";
      case -0x7ff6fcbd:
        return L"SEC_E_UNSUPPORTED_PREAUTH";
      case -0x7ff6fcbb:
        return L"SEC_E_DELEGATION_REQUIRED";
      case -0x7ff6fcba:
        return L"SEC_E_BAD_BINDINGS";
      case -0x7ff6fcb9:
        return L"SEC_E_MULTIPLE_ACCOUNTS";
      case -0x7ff6fcb8:
        return L"SEC_E_NO_KERB_KEY";
      case -0x7ff6fcaf:
        return L"SEC_E_SMARTCARD_CERT_REVOKED";
      case -0x7ff6fcae:
        return L"SEC_E_ISSUING_CA_UNTRUSTED";
      case -0x7ff6fcad:
        return L"SEC_E_REVOCATION_OFFLINE_C";
      case -0x7ff6fcac:
        return L"SEC_E_PKINIT_CLIENT_FAILURE";
      case -0x7ff6fcab:
        return L"SEC_E_SMARTCARD_CERT_EXPIRED";
      }
    }
    else if (param_1 < -0x7ff6dffe) {
      if (param_1 == -0x7ff6dfff) {
        return L"CRYPT_E_BAD_LEN";
      }
      switch(param_1) {
      case -0x7ff6effe:
        return L"CRYPT_E_UNKNOWN_ALGO";
      case -0x7ff6effd:
        return L"CRYPT_E_OID_FORMAT";
      case -0x7ff6effc:
        return L"CRYPT_E_INVALID_MSG_TYPE";
      case -0x7ff6effb:
        return L"CRYPT_E_UNEXPECTED_ENCODING";
      case -0x7ff6effa:
        return L"CRYPT_E_AUTH_ATTR_MISSING";
      case -0x7ff6eff9:
        return L"CRYPT_E_HASH_VALUE";
      case -0x7ff6eff8:
        return L"CRYPT_E_INVALID_INDEX";
      case -0x7ff6eff7:
        return L"CRYPT_E_ALREADY_DECRYPTED";
      case -0x7ff6eff6:
        return L"CRYPT_E_NOT_DECRYPTED";
      case -0x7ff6eff5:
        return L"CRYPT_E_RECIPIENT_NOT_FOUND";
      case -0x7ff6eff4:
        return L"CRYPT_E_CONTROL_TYPE";
      case -0x7ff6eff3:
        return L"CRYPT_E_ISSUER_SERIALNUMBER";
      case -0x7ff6eff2:
        return L"CRYPT_E_SIGNER_NOT_FOUND";
      case -0x7ff6eff1:
        return L"CRYPT_E_ATTRIBUTES_MISSING";
      case -0x7ff6eff0:
        return L"CRYPT_E_STREAM_MSG_NOT_READY";
      case -0x7ff6efef:
        return L"CRYPT_E_STREAM_INSUFFICIENT_DATA";
      }
    }
    else if (param_1 < -0x7ff6cfff) {
      if (param_1 == -0x7ff6d000) {
        return L"CRYPT_E_OSS_ERROR";
      }
      switch(param_1) {
      case -0x7ff6dffe:
        return L"CRYPT_E_BAD_ENCODE";
      case -0x7ff6dffd:
        return L"CRYPT_E_FILE_ERROR";
      case -0x7ff6dffc:
        return L"CRYPT_E_NOT_FOUND";
      case -0x7ff6dffb:
        return L"CRYPT_E_EXISTS";
      case -0x7ff6dffa:
        return L"CRYPT_E_NO_PROVIDER";
      case -0x7ff6dff9:
        return L"CRYPT_E_SELF_SIGNED";
      case -0x7ff6dff8:
        return L"CRYPT_E_DELETED_PREV";
      case -0x7ff6dff7:
        return L"CRYPT_E_NO_MATCH";
      case -0x7ff6dff6:
        return L"CRYPT_E_UNEXPECTED_MSG_TYPE";
      case -0x7ff6dff5:
        return L"CRYPT_E_NO_KEY_PROPERTY";
      case -0x7ff6dff4:
        return L"CRYPT_E_NO_DECRYPT_CERT";
      case -0x7ff6dff3:
        return L"CRYPT_E_BAD_MSG";
      case -0x7ff6dff2:
        return L"CRYPT_E_NO_SIGNER";
      case -0x7ff6dff1:
        return L"CRYPT_E_PENDING_CLOSE";
      case -0x7ff6dff0:
        return L"CRYPT_E_REVOKED";
      case -0x7ff6dfef:
        return L"CRYPT_E_NO_REVOCATION_DLL";
      case -0x7ff6dfee:
        return L"CRYPT_E_NO_REVOCATION_CHECK";
      case -0x7ff6dfed:
        return L"CRYPT_E_REVOCATION_OFFLINE";
      case -0x7ff6dfec:
        return L"CRYPT_E_NOT_IN_REVOCATION_DATABASE";
      case -0x7ff6dfe0:
        return L"CRYPT_E_INVALID_NUMERIC_STRING";
      case -0x7ff6dfdf:
        return L"CRYPT_E_INVALID_PRINTABLE_STRING";
      case -0x7ff6dfde:
        return L"CRYPT_E_INVALID_IA5_STRING";
      case -0x7ff6dfdd:
        return L"CRYPT_E_INVALID_X500_STRING";
      case -0x7ff6dfdc:
        return L"CRYPT_E_NOT_CHAR_STRING";
      case -0x7ff6dfdb:
        return L"CRYPT_E_FILERESIZED";
      case -0x7ff6dfda:
        return L"CRYPT_E_SECURITY_SETTINGS";
      case -0x7ff6dfd9:
        return L"CRYPT_E_NO_VERIFY_USAGE_DLL";
      case -0x7ff6dfd8:
        return L"CRYPT_E_NO_VERIFY_USAGE_CHECK";
      case -0x7ff6dfd7:
        return L"CRYPT_E_VERIFY_USAGE_OFFLINE";
      case -0x7ff6dfd6:
        return L"CRYPT_E_NOT_IN_CTL";
      case -0x7ff6dfd5:
        return L"CRYPT_E_NO_TRUSTED_SIGNER";
      case -0x7ff6dfd4:
        return L"CRYPT_E_MISSING_PUBKEY_PARA";
      }
    }
    else if (param_1 < -0x7ff6ceff) {
      if (param_1 == -0x7ff6cf00) {
        return L"CRYPT_E_ASN1_ERROR";
      }
      switch(param_1) {
      case -0x7ff6cfff:
        return L"OSS_MORE_BUF";
      case -0x7ff6cffe:
        return L"OSS_NEGATIVE_UINTEGER";
      case -0x7ff6cffd:
        return L"OSS_PDU_RANGE";
      case -0x7ff6cffc:
        return L"OSS_MORE_INPUT";
      case -0x7ff6cffb:
        return L"OSS_DATA_ERROR";
      case -0x7ff6cffa:
        return L"OSS_BAD_ARG";
      case -0x7ff6cff9:
        return L"OSS_BAD_VERSION";
      case -0x7ff6cff8:
        return L"OSS_OUT_MEMORY";
      case -0x7ff6cff7:
        return L"OSS_PDU_MISMATCH";
      case -0x7ff6cff6:
        return L"OSS_LIMITED";
      case -0x7ff6cff5:
        return L"OSS_BAD_PTR";
      case -0x7ff6cff4:
        return L"OSS_BAD_TIME";
      case -0x7ff6cff3:
        return L"OSS_INDEFINITE_NOT_SUPPORTED";
      case -0x7ff6cff2:
        return L"OSS_MEM_ERROR";
      case -0x7ff6cff1:
        return L"OSS_BAD_TABLE";
      case -0x7ff6cff0:
        return L"OSS_TOO_LONG";
      case -0x7ff6cfef:
        return L"OSS_CONSTRAINT_VIOLATED";
      case -0x7ff6cfee:
        return L"OSS_FATAL_ERROR";
      case -0x7ff6cfed:
        return L"OSS_ACCESS_SERIALIZATION_ERROR";
      case -0x7ff6cfec:
        return L"OSS_NULL_TBL";
      case -0x7ff6cfeb:
        return L"OSS_NULL_FCN";
      case -0x7ff6cfea:
        return L"OSS_BAD_ENCRULES";
      case -0x7ff6cfe9:
        return L"OSS_UNAVAIL_ENCRULES";
      case -0x7ff6cfe8:
        return L"OSS_CANT_OPEN_TRACE_WINDOW";
      case -0x7ff6cfe7:
        return L"OSS_UNIMPLEMENTED";
      case -0x7ff6cfe6:
        return L"OSS_OID_DLL_NOT_LINKED";
      case -0x7ff6cfe5:
        return L"OSS_CANT_OPEN_TRACE_FILE";
      case -0x7ff6cfe4:
        return L"OSS_TRACE_FILE_ALREADY_OPEN";
      case -0x7ff6cfe3:
        return L"OSS_TABLE_MISMATCH";
      case -0x7ff6cfe2:
        return L"OSS_TYPE_NOT_SUPPORTED";
      case -0x7ff6cfe1:
        return L"OSS_REAL_DLL_NOT_LINKED";
      case -0x7ff6cfe0:
        return L"OSS_REAL_CODE_NOT_LINKED";
      case -0x7ff6cfdf:
        return L"OSS_OUT_OF_RANGE";
      case -0x7ff6cfde:
        return L"OSS_COPIER_DLL_NOT_LINKED";
      case -0x7ff6cfdd:
        return L"OSS_CONSTRAINT_DLL_NOT_LINKED";
      case -0x7ff6cfdc:
        return L"OSS_COMPARATOR_DLL_NOT_LINKED";
      case -0x7ff6cfdb:
        return L"OSS_COMPARATOR_CODE_NOT_LINKED";
      case -0x7ff6cfda:
        return L"OSS_MEM_MGR_DLL_NOT_LINKED";
      case -0x7ff6cfd9:
        return L"OSS_PDV_DLL_NOT_LINKED";
      case -0x7ff6cfd8:
        return L"OSS_PDV_CODE_NOT_LINKED";
      case -0x7ff6cfd7:
        return L"OSS_API_DLL_NOT_LINKED";
      case -0x7ff6cfd6:
        return L"OSS_BERDER_DLL_NOT_LINKED";
      case -0x7ff6cfd5:
        return L"OSS_PER_DLL_NOT_LINKED";
      case -0x7ff6cfd4:
        return L"OSS_OPEN_TYPE_ERROR";
      case -0x7ff6cfd3:
        return L"OSS_MUTEX_NOT_CREATED";
      case -0x7ff6cfd2:
        return L"OSS_CANT_CLOSE_TRACE_FILE";
      }
    }
    else if (param_1 == -0x7ff6ceff) {
      return L"CRYPT_E_ASN1_INTERNAL";
    }
  }
  else if (param_1 < -0x7ff6cecc) {
    if (param_1 == -0x7ff6cecd) {
      return L"CRYPT_E_ASN1_PDU_TYPE";
    }
    switch(param_1) {
    case -0x7ff6cefd:
      return L"CRYPT_E_ASN1_CORRUPT";
    case -0x7ff6cefc:
      return L"CRYPT_E_ASN1_LARGE";
    case -0x7ff6cefb:
      return L"CRYPT_E_ASN1_CONSTRAINT";
    case -0x7ff6cefa:
      return L"CRYPT_E_ASN1_MEMORY";
    case -0x7ff6cef9:
      return L"CRYPT_E_ASN1_OVERFLOW";
    case -0x7ff6cef8:
      return L"CRYPT_E_ASN1_BADPDU";
    case -0x7ff6cef7:
      return L"CRYPT_E_ASN1_BADARGS";
    case -0x7ff6cef6:
      return L"CRYPT_E_ASN1_BADREAL";
    case -0x7ff6cef5:
      return L"CRYPT_E_ASN1_BADTAG";
    case -0x7ff6cef4:
      return L"CRYPT_E_ASN1_CHOICE";
    case -0x7ff6cef3:
      return L"CRYPT_E_ASN1_RULE";
    case -0x7ff6cef2:
      return L"CRYPT_E_ASN1_UTF8";
    }
  }
  else if (param_1 < 0x5b4) {
    if (param_1 == 0x5b3) {
LAB_0072f536:
      return L"ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION";
    }
    if (param_1 < -0x7787eed8) {
      if (param_1 == -0x7787eed9) {
        return L"DMUS_E_BADINSTRUMENT";
      }
      if (param_1 < -0x7feef7e1) {
        if (param_1 == -0x7feef7e2) {
          return L"COMADMIN_E_COMP_MOVE_PRIVATE";
        }
        if (param_1 < -0x7ff0fdc9) {
          if (param_1 == -0x7ff0fdca) {
            return L"SPAPI_E_SET_SYSTEM_RESTORE_POINT";
          }
          if (param_1 < -0x7ff4fff5) {
            if (param_1 == -0x7ff4fff6) {
              return L"PERSIST_E_SIZEINDEFINITE";
            }
            if (param_1 < -0x7ff6affc) {
              if (param_1 == -0x7ff6affd) {
                return L"XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH";
              }
              if (param_1 < -0x7ff6b7ff) {
                if (param_1 == -0x7ff6b800) {
                  return L"CERTSRV_E_UNSUPPORTED_CERT_TYPE";
                }
                if (param_1 < -0x7ff6bff7) {
                  if (param_1 == -0x7ff6bff8) {
                    return L"CERTSRV_E_ROLECONFLICT";
                  }
                  if (param_1 < -0x7ff6bffc) {
                    if (param_1 == -0x7ff6bffd) {
                      return L"CERTSRV_E_BAD_REQUESTSTATUS";
                    }
                    if (param_1 == -0x7ff6cecc) {
                      return L"CRYPT_E_ASN1_NYI";
                    }
                    if (param_1 == -0x7ff6cdff) {
                      return L"CRYPT_E_ASN1_EXTENDED";
                    }
                    if (param_1 == -0x7ff6cdfe) {
                      return L"CRYPT_E_ASN1_NOEOD";
                    }
                    if (param_1 == -0x7ff6bfff) {
                      return L"CERTSRV_E_BAD_REQUESTSUBJECT";
                    }
                    if (param_1 == -0x7ff6bffe) {
                      return L"CERTSRV_E_NO_REQUEST";
                    }
                  }
                  else {
                    if (param_1 == -0x7ff6bffc) {
                      return L"CERTSRV_E_PROPERTY_EMPTY";
                    }
                    if (param_1 == -0x7ff6bffb) {
                      return L"CERTSRV_E_INVALID_CA_CERTIFICATE";
                    }
                    if (param_1 == -0x7ff6bffa) {
                      return L"CERTSRV_E_SERVER_SUSPENDED";
                    }
                    if (param_1 == -0x7ff6bff9) {
                      return L"CERTSRV_E_ENCODING_LENGTH";
                    }
                  }
                }
                else {
                  switch(param_1) {
                  case -0x7ff6bff7:
                    return L"CERTSRV_E_RESTRICTEDOFFICER";
                  case -0x7ff6bff6:
                    return L"CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED";
                  case -0x7ff6bff5:
                    return L"CERTSRV_E_NO_VALID_KRA";
                  case -0x7ff6bff4:
                    return L"CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL";
                  case -0x7ff6bff3:
                    return L"CERTSRV_E_NO_CAADMIN_DEFINED";
                  case -0x7ff6bff2:
                    return L"CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE";
                  case -0x7ff6bff1:
                    return L"CERTSRV_E_NO_DB_SESSIONS";
                  case -0x7ff6bff0:
                    return L"CERTSRV_E_ALIGNMENT_FAULT";
                  case -0x7ff6bfef:
                    return L"CERTSRV_E_ENROLL_DENIED";
                  case -0x7ff6bfee:
                    return L"CERTSRV_E_TEMPLATE_DENIED";
                  }
                }
              }
              else if (param_1 < -0x7ff6afff) {
                if (param_1 == -0x7ff6b000) {
                  return L"XENROLL_E_KEY_NOT_EXPORTABLE";
                }
                switch(param_1) {
                case -0x7ff6b7ff:
                  return L"CERTSRV_E_NO_CERT_TYPE";
                case -0x7ff6b7fe:
                  return L"CERTSRV_E_TEMPLATE_CONFLICT";
                case -0x7ff6b7fd:
                  return L"CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED";
                case -0x7ff6b7fc:
                  return L"CERTSRV_E_ARCHIVED_KEY_REQUIRED";
                case -0x7ff6b7fb:
                  return L"CERTSRV_E_SMIME_REQUIRED";
                case -0x7ff6b7fa:
                  return L"CERTSRV_E_BAD_RENEWAL_SUBJECT";
                case -0x7ff6b7f9:
                  return L"CERTSRV_E_BAD_TEMPLATE_VERSION";
                case -0x7ff6b7f8:
                  return L"CERTSRV_E_TEMPLATE_POLICY_REQUIRED";
                case -0x7ff6b7f7:
                  return L"CERTSRV_E_SIGNATURE_POLICY_REQUIRED";
                case -0x7ff6b7f6:
                  return L"CERTSRV_E_SIGNATURE_COUNT";
                case -0x7ff6b7f5:
                  return L"CERTSRV_E_SIGNATURE_REJECTED";
                case -0x7ff6b7f4:
                  return L"CERTSRV_E_ISSUANCE_POLICY_REQUIRED";
                case -0x7ff6b7f3:
                  return L"CERTSRV_E_SUBJECT_UPN_REQUIRED";
                case -0x7ff6b7f2:
                  return L"CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED";
                case -0x7ff6b7f1:
                  return L"CERTSRV_E_SUBJECT_DNS_REQUIRED";
                case -0x7ff6b7f0:
                  return L"CERTSRV_E_ARCHIVED_KEY_UNEXPECTED";
                case -0x7ff6b7ef:
                  return L"CERTSRV_E_KEY_LENGTH";
                }
              }
              else {
                if (param_1 == -0x7ff6afff) {
                  return L"XENROLL_E_CANNOT_ADD_ROOT_CERT";
                }
                if (param_1 == -0x7ff6affe) {
                  return L"XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND";
                }
              }
            }
            else if (param_1 < -0x7ff68ff4) {
              if (param_1 == -0x7ff68ff5) {
                return L"MSSIPOTF_E_FILETOOSMALL";
              }
              if (param_1 < -0x7ff68ffe) {
                if (param_1 == -0x7ff68fff) {
                  return L"MSSIPOTF_E_OUTOFMEMRANGE";
                }
                if (param_1 < -0x7ff69ffb) {
                  if (param_1 == -0x7ff69ffc) {
                    return L"TRUST_E_CERT_SIGNATURE";
                  }
                  if (param_1 == -0x7ff6affc) {
                    return L"XENROLL_E_RESPONSE_KA_HASH_MISMATCH";
                  }
                  if (param_1 == -0x7ff6affb) {
                    return L"XENROLL_E_KEYSPEC_SMIME_MISMATCH";
                  }
                  if (param_1 == -0x7ff69fff) {
                    return L"TRUST_E_SYSTEM_ERROR";
                  }
                  if (param_1 == -0x7ff69ffe) {
                    return L"TRUST_E_NO_SIGNER_CERT";
                  }
                  if (param_1 == -0x7ff69ffd) {
                    return L"TRUST_E_COUNTER_SIGNER";
                  }
                }
                else {
                  if (param_1 == -0x7ff69ffb) {
                    return L"TRUST_E_TIME_STAMP";
                  }
                  if (param_1 == -0x7ff69ff0) {
                    return L"TRUST_E_BAD_DIGEST";
                  }
                  if (param_1 == -0x7ff69fe7) {
                    return L"TRUST_E_BASIC_CONSTRAINTS";
                  }
                  if (param_1 == -0x7ff69fe2) {
                    return L"TRUST_E_FINANCIAL_CRITERIA";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ff68ffe:
                  return L"MSSIPOTF_E_CANTGETOBJECT";
                case -0x7ff68ffd:
                  return L"MSSIPOTF_E_NOHEADTABLE";
                case -0x7ff68ffc:
                  return L"MSSIPOTF_E_BAD_MAGICNUMBER";
                case -0x7ff68ffb:
                  return L"MSSIPOTF_E_BAD_OFFSET_TABLE";
                case -0x7ff68ffa:
                  return L"MSSIPOTF_E_TABLE_TAGORDER";
                case -0x7ff68ff9:
                  return L"MSSIPOTF_E_TABLE_LONGWORD";
                case -0x7ff68ff8:
                  return L"MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT";
                case -0x7ff68ff7:
                  return L"MSSIPOTF_E_TABLES_OVERLAP";
                case -0x7ff68ff6:
                  return L"MSSIPOTF_E_TABLE_PADBYTES";
                }
              }
            }
            else if (param_1 < -0x7ff4fffe) {
              if (param_1 == -0x7ff4ffff) {
                return L"TRUST_E_PROVIDER_UNKNOWN";
              }
              switch(param_1) {
              case -0x7ff68ff4:
                return L"MSSIPOTF_E_TABLE_CHECKSUM";
              case -0x7ff68ff3:
                return L"MSSIPOTF_E_FILE_CHECKSUM";
              case -0x7ff68ff0:
                return L"MSSIPOTF_E_FAILED_POLICY";
              case -0x7ff68fef:
                return L"MSSIPOTF_E_FAILED_HINTS_CHECK";
              case -0x7ff68fee:
                return L"MSSIPOTF_E_NOT_OPENTYPE";
              case -0x7ff68fed:
                return L"MSSIPOTF_E_FILE";
              case -0x7ff68fec:
                return L"MSSIPOTF_E_CRYPT";
              case -0x7ff68feb:
                return L"MSSIPOTF_E_BADVERSION";
              case -0x7ff68fea:
                return L"MSSIPOTF_E_DSIG_STRUCTURE";
              case -0x7ff68fe9:
                return L"MSSIPOTF_E_PCONST_CHECK";
              case -0x7ff68fe8:
                return L"MSSIPOTF_E_STRUCTURE";
              }
            }
            else {
              switch(param_1) {
              case -0x7ff4fffe:
                return L"TRUST_E_ACTION_UNKNOWN";
              case -0x7ff4fffd:
                return L"TRUST_E_SUBJECT_FORM_UNKNOWN";
              case -0x7ff4fffc:
                return L"TRUST_E_SUBJECT_NOT_TRUSTED";
              case -0x7ff4fffb:
                return L"DIGSIG_E_ENCODE";
              case -0x7ff4fffa:
                return L"DIGSIG_E_DECODE";
              case -0x7ff4fff9:
                return L"DIGSIG_E_EXTENSIBILITY";
              case -0x7ff4fff8:
                return L"DIGSIG_E_CRYPTO";
              case -0x7ff4fff7:
                return L"PERSIST_E_SIZEDEFINITE";
              }
            }
          }
          else if (param_1 < -0x7ff0fdf3) {
            if (param_1 == -0x7ff0fdf4) {
              return L"SPAPI_E_CANT_LOAD_CLASS_ICON";
            }
            if (param_1 < -0x7ff4feeb) {
              if (param_1 == -0x7ff4feec) {
                return L"CERT_E_INVALID_NAME";
              }
              if (param_1 < -0x7ff4fef6) {
                if (param_1 == -0x7ff4fef7) {
                  return L"CERT_E_UNTRUSTEDROOT";
                }
                if (param_1 < -0x7ff4fefb) {
                  if (param_1 == -0x7ff4fefc) {
                    return L"CERT_E_PATHLENCONST";
                  }
                  if (param_1 == -0x7ff4fff5) {
                    return L"PERSIST_E_NOTSELFSIZING";
                  }
                  if (param_1 == -0x7ff4ff00) {
                    return L"TRUST_E_NOSIGNATURE";
                  }
                  if (param_1 == -0x7ff4feff) {
                    return L"CERT_E_EXPIRED";
                  }
                  if (param_1 == -0x7ff4fefe) {
                    return L"CERT_E_VALIDITYPERIODNESTING";
                  }
                  if (param_1 == -0x7ff4fefd) {
                    return L"CERT_E_ROLE";
                  }
                }
                else {
                  if (param_1 == -0x7ff4fefb) {
                    return L"CERT_E_CRITICAL";
                  }
                  if (param_1 == -0x7ff4fefa) {
                    return L"CERT_E_PURPOSE";
                  }
                  if (param_1 == -0x7ff4fef9) {
                    return L"CERT_E_ISSUERCHAINING";
                  }
                  if (param_1 == -0x7ff4fef8) {
                    return L"CERT_E_MALFORMED";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ff4fef6:
                  return L"CERT_E_CHAINING";
                case -0x7ff4fef5:
                  return L"TRUST_E_FAIL";
                case -0x7ff4fef4:
                  return L"CERT_E_REVOKED";
                case -0x7ff4fef3:
                  return L"CERT_E_UNTRUSTEDTESTROOT";
                case -0x7ff4fef2:
                  return L"CERT_E_REVOCATION_FAILURE";
                case -0x7ff4fef1:
                  return L"CERT_E_CN_NO_MATCH";
                case -0x7ff4fef0:
                  return L"CERT_E_WRONG_USAGE";
                case -0x7ff4feef:
                  return L"TRUST_E_EXPLICIT_DISTRUST";
                case -0x7ff4feee:
                  return L"CERT_E_UNTRUSTEDCA";
                case -0x7ff4feed:
                  return L"CERT_E_INVALID_POLICY";
                }
              }
            }
            else if (param_1 < -0x7ff0fdfd) {
              if (param_1 == -0x7ff0fdfe) {
                return L"SPAPI_E_DUPLICATE_FOUND";
              }
              if (param_1 < -0x7ff0fefe) {
                if (param_1 == -0x7ff0feff) {
                  return L"SPAPI_E_SECTION_NOT_FOUND";
                }
                if (param_1 == -0x7ff10000) {
                  return L"SPAPI_E_EXPECTED_SECTION_NAME";
                }
                if (param_1 == -0x7ff0ffff) {
                  return L"SPAPI_E_BAD_SECTION_NAME_LINE";
                }
                if (param_1 == -0x7ff0fffe) {
                  return L"SPAPI_E_SECTION_NAME_TOO_LONG";
                }
                if (param_1 == -0x7ff0fffd) {
                  return L"SPAPI_E_GENERAL_SYNTAX";
                }
                if (param_1 == -0x7ff0ff00) {
                  return L"SPAPI_E_WRONG_INF_STYLE";
                }
              }
              else {
                if (param_1 == -0x7ff0fefe) {
                  return L"SPAPI_E_LINE_NOT_FOUND";
                }
                if (param_1 == -0x7ff0fefd) {
                  return L"SPAPI_E_NO_BACKUP";
                }
                if (param_1 == -0x7ff0fe00) {
                  return L"SPAPI_E_NO_ASSOCIATED_CLASS";
                }
                if (param_1 == -0x7ff0fdff) {
                  return L"SPAPI_E_CLASS_MISMATCH";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7ff0fdfd:
                return L"SPAPI_E_NO_DRIVER_SELECTED";
              case -0x7ff0fdfc:
                return L"SPAPI_E_KEY_DOES_NOT_EXIST";
              case -0x7ff0fdfb:
                return L"SPAPI_E_INVALID_DEVINST_NAME";
              case -0x7ff0fdfa:
                return L"SPAPI_E_INVALID_CLASS";
              case -0x7ff0fdf9:
                return L"SPAPI_E_DEVINST_ALREADY_EXISTS";
              case -0x7ff0fdf8:
                return L"SPAPI_E_DEVINFO_NOT_REGISTERED";
              case -0x7ff0fdf7:
                return L"SPAPI_E_INVALID_REG_PROPERTY";
              case -0x7ff0fdf6:
                return L"SPAPI_E_NO_INF";
              case -0x7ff0fdf5:
                return L"SPAPI_E_NO_SUCH_DEVINST";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ff0fdf3:
              return L"SPAPI_E_INVALID_CLASS_INSTALLER";
            case -0x7ff0fdf2:
              return L"SPAPI_E_DI_DO_DEFAULT";
            case -0x7ff0fdf1:
              return L"SPAPI_E_DI_NOFILECOPY";
            case -0x7ff0fdf0:
              return L"SPAPI_E_INVALID_HWPROFILE";
            case -0x7ff0fdef:
              return L"SPAPI_E_NO_DEVICE_SELECTED";
            case -0x7ff0fdee:
              return L"SPAPI_E_DEVINFO_LIST_LOCKED";
            case -0x7ff0fded:
              return L"SPAPI_E_DEVINFO_DATA_LOCKED";
            case -0x7ff0fdec:
              return L"SPAPI_E_DI_BAD_PATH";
            case -0x7ff0fdeb:
              return L"SPAPI_E_NO_CLASSINSTALL_PARAMS";
            case -0x7ff0fdea:
              return L"SPAPI_E_FILEQUEUE_LOCKED";
            case -0x7ff0fde9:
              return L"SPAPI_E_BAD_SERVICE_INSTALLSECT";
            case -0x7ff0fde8:
              return L"SPAPI_E_NO_CLASS_DRIVER_LIST";
            case -0x7ff0fde7:
              return L"SPAPI_E_NO_ASSOCIATED_SERVICE";
            case -0x7ff0fde6:
              return L"SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE";
            case -0x7ff0fde5:
              return L"SPAPI_E_DEVICE_INTERFACE_ACTIVE";
            case -0x7ff0fde4:
              return L"SPAPI_E_DEVICE_INTERFACE_REMOVED";
            case -0x7ff0fde3:
              return L"SPAPI_E_BAD_INTERFACE_INSTALLSECT";
            case -0x7ff0fde2:
              return L"SPAPI_E_NO_SUCH_INTERFACE_CLASS";
            case -0x7ff0fde1:
              return L"SPAPI_E_INVALID_REFERENCE_STRING";
            case -0x7ff0fde0:
              return L"SPAPI_E_INVALID_MACHINENAME";
            case -0x7ff0fddf:
              return L"SPAPI_E_REMOTE_COMM_FAILURE";
            case -0x7ff0fdde:
              return L"SPAPI_E_MACHINE_UNAVAILABLE";
            case -0x7ff0fddd:
              return L"SPAPI_E_NO_CONFIGMGR_SERVICES";
            case -0x7ff0fddc:
              return L"SPAPI_E_INVALID_PROPPAGE_PROVIDER";
            case -0x7ff0fddb:
              return L"SPAPI_E_NO_SUCH_DEVICE_INTERFACE";
            case -0x7ff0fdda:
              return L"SPAPI_E_DI_POSTPROCESSING_REQUIRED";
            case -0x7ff0fdd9:
              return L"SPAPI_E_INVALID_COINSTALLER";
            case -0x7ff0fdd8:
              return L"SPAPI_E_NO_COMPAT_DRIVERS";
            case -0x7ff0fdd7:
              return L"SPAPI_E_NO_DEVICE_ICON";
            case -0x7ff0fdd6:
              return L"SPAPI_E_INVALID_INF_LOGCONFIG";
            case -0x7ff0fdd5:
              return L"SPAPI_E_DI_DONT_INSTALL";
            case -0x7ff0fdd4:
              return L"SPAPI_E_INVALID_FILTER_DRIVER";
            case -0x7ff0fdd3:
              return L"SPAPI_E_NON_WINDOWS_NT_DRIVER";
            case -0x7ff0fdd2:
              return L"SPAPI_E_NON_WINDOWS_DRIVER";
            case -0x7ff0fdd1:
              return L"SPAPI_E_NO_CATALOG_FOR_OEM_INF";
            case -0x7ff0fdd0:
              return L"SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE";
            case -0x7ff0fdcf:
              return L"SPAPI_E_NOT_DISABLEABLE";
            case -0x7ff0fdce:
              return L"SPAPI_E_CANT_REMOVE_DEVINST";
            case -0x7ff0fdcd:
              return L"SPAPI_E_INVALID_TARGET";
            case -0x7ff0fdcc:
              return L"SPAPI_E_DRIVER_NONNATIVE";
            case -0x7ff0fdcb:
              return L"SPAPI_E_IN_WOW64";
            }
          }
        }
        else if (param_1 < -0x7feefbe1) {
          if (param_1 == -0x7feefbe2) {
            return L"COMADMIN_E_BADREGISTRYLIBID";
          }
          if (param_1 < -0x7fefffd7) {
            if (param_1 == -0x7fefffd8) {
              return L"SCARD_E_WRITE_TOO_MANY";
            }
            if (param_1 < -0x7fefffec) {
              if (param_1 == -0x7fefffed) {
                return L"SCARD_F_COMM_ERROR";
              }
              if (param_1 < -0x7feffff7) {
                if (param_1 == -0x7feffff8) {
                  return L"SCARD_E_INSUFFICIENT_BUFFER";
                }
                if (param_1 < -0x7feffffc) {
                  if (param_1 == -0x7feffffd) {
                    return L"SCARD_E_INVALID_HANDLE";
                  }
                  if (param_1 == -0x7ff0fdc9) {
                    return L"SPAPI_E_INCORRECTLY_COPIED_INF";
                  }
                  if (param_1 == -0x7ff0fdc8) {
                    return L"SPAPI_E_SCE_DISABLED";
                  }
                  if (param_1 == -0x7ff0f000) {
                    return L"SPAPI_E_ERROR_NOT_INSTALLED";
                  }
                  if (param_1 == -0x7fefffff) {
                    return L"SCARD_F_INTERNAL_ERROR";
                  }
                  if (param_1 == -0x7feffffe) {
                    return L"SCARD_E_CANCELLED";
                  }
                }
                else {
                  if (param_1 == -0x7feffffc) {
                    return L"SCARD_E_INVALID_PARAMETER";
                  }
                  if (param_1 == -0x7feffffb) {
                    return L"SCARD_E_INVALID_TARGET";
                  }
                  if (param_1 == -0x7feffffa) {
                    return L"SCARD_E_NO_MEMORY";
                  }
                  if (param_1 == -0x7feffff9) {
                    return L"SCARD_F_WAITED_TOO_LONG";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7feffff7:
                  return L"SCARD_E_UNKNOWN_READER";
                case -0x7feffff6:
                  return L"SCARD_E_TIMEOUT";
                case -0x7feffff5:
                  return L"SCARD_E_SHARING_VIOLATION";
                case -0x7feffff4:
                  return L"SCARD_E_NO_SMARTCARD";
                case -0x7feffff3:
                  return L"SCARD_E_UNKNOWN_CARD";
                case -0x7feffff2:
                  return L"SCARD_E_CANT_DISPOSE";
                case -0x7feffff1:
                  return L"SCARD_E_PROTO_MISMATCH";
                case -0x7feffff0:
                  return L"SCARD_E_NOT_READY";
                case -0x7fefffef:
                  return L"SCARD_E_INVALID_VALUE";
                case -0x7fefffee:
                  return L"SCARD_E_SYSTEM_CANCELLED";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7fefffec:
                return L"SCARD_F_UNKNOWN_ERROR";
              case -0x7fefffeb:
                return L"SCARD_E_INVALID_ATR";
              case -0x7fefffea:
                return L"SCARD_E_NOT_TRANSACTED";
              case -0x7fefffe9:
                return L"SCARD_E_READER_UNAVAILABLE";
              case -0x7fefffe8:
                return L"SCARD_P_SHUTDOWN";
              case -0x7fefffe7:
                return L"SCARD_E_PCI_TOO_SMALL";
              case -0x7fefffe6:
                return L"SCARD_E_READER_UNSUPPORTED";
              case -0x7fefffe5:
                return L"SCARD_E_DUPLICATE_READER";
              case -0x7fefffe4:
                return L"SCARD_E_CARD_UNSUPPORTED";
              case -0x7fefffe3:
                return L"SCARD_E_NO_SERVICE";
              case -0x7fefffe2:
                return L"SCARD_E_SERVICE_STOPPED";
              case -0x7fefffe1:
                return L"SCARD_E_UNEXPECTED";
              case -0x7fefffe0:
                return L"SCARD_E_ICC_INSTALLATION";
              case -0x7fefffdf:
                return L"SCARD_E_ICC_CREATEORDER";
              case -0x7fefffde:
                return L"SCARD_E_UNSUPPORTED_FEATURE";
              case -0x7fefffdd:
                return L"SCARD_E_DIR_NOT_FOUND";
              case -0x7fefffdc:
                return L"SCARD_E_FILE_NOT_FOUND";
              case -0x7fefffdb:
                return L"SCARD_E_NO_DIR";
              case -0x7fefffda:
                return L"SCARD_E_NO_FILE";
              case -0x7fefffd9:
                return L"SCARD_E_NO_ACCESS";
              }
            }
          }
          else if (param_1 < -0x7feefbfd) {
            if (param_1 == -0x7feefbfe) {
              return L"COMADMIN_E_OBJECTINVALID";
            }
            if (param_1 < -0x7fefff98) {
              if (param_1 == -0x7fefff99) {
                return L"SCARD_W_UNPOWERED_CARD";
              }
              if (param_1 < -0x7fefffd1) {
                if (param_1 == -0x7fefffd2) {
                  return L"SCARD_E_NO_READERS_AVAILABLE";
                }
                if (param_1 == -0x7fefffd7) {
                  return L"SCARD_E_BAD_SEEK";
                }
                if (param_1 == -0x7fefffd6) {
                  return L"SCARD_E_INVALID_CHV";
                }
                if (param_1 == -0x7fefffd5) {
                  return L"SCARD_E_UNKNOWN_RES_MNG";
                }
                if (param_1 == -0x7fefffd4) {
                  return L"SCARD_E_NO_SUCH_CERTIFICATE";
                }
                if (param_1 == -0x7fefffd3) {
                  return L"SCARD_E_CERTIFICATE_UNAVAILABLE";
                }
              }
              else {
                if (param_1 == -0x7fefffd1) {
                  return L"SCARD_E_COMM_DATA_LOST";
                }
                if (param_1 == -0x7fefffd0) {
                  return L"SCARD_E_NO_KEY_CONTAINER";
                }
                if (param_1 == -0x7fefff9b) {
                  return L"SCARD_W_UNSUPPORTED_CARD";
                }
                if (param_1 == -0x7fefff9a) {
                  return L"SCARD_W_UNRESPONSIVE_CARD";
                }
              }
            }
            else if (param_1 < -0x7fefff93) {
              if (param_1 == -0x7fefff94) {
                return L"SCARD_W_CHV_BLOCKED";
              }
              if (param_1 == -0x7fefff98) {
                return L"SCARD_W_RESET_CARD";
              }
              if (param_1 == -0x7fefff97) {
                return L"SCARD_W_REMOVED_CARD";
              }
              if (param_1 == -0x7fefff96) {
                return L"SCARD_W_SECURITY_VIOLATION";
              }
              if (param_1 == -0x7fefff95) {
                return L"SCARD_W_WRONG_CHV";
              }
            }
            else {
              if (param_1 == -0x7fefff93) {
                return L"SCARD_W_EOF";
              }
              if (param_1 == -0x7fefff92) {
                return L"SCARD_W_CANCELLED_BY_USER";
              }
              if (param_1 == -0x7fefff91) {
                return L"SCARD_W_CARD_NOT_AUTHENTICATED";
              }
              if (param_1 == -0x7feefbff) {
                return L"COMADMIN_E_OBJECTERRORS";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7feefbfd:
              return L"COMADMIN_E_KEYMISSING";
            case -0x7feefbfc:
              return L"COMADMIN_E_ALREADYINSTALLED";
            case -0x7feefbf9:
              return L"COMADMIN_E_APP_FILE_WRITEFAIL";
            case -0x7feefbf8:
              return L"COMADMIN_E_APP_FILE_READFAIL";
            case -0x7feefbf7:
              return L"COMADMIN_E_APP_FILE_VERSION";
            case -0x7feefbf6:
              return L"COMADMIN_E_BADPATH";
            case -0x7feefbf5:
              return L"COMADMIN_E_APPLICATIONEXISTS";
            case -0x7feefbf4:
              return L"COMADMIN_E_ROLEEXISTS";
            case -0x7feefbf3:
              return L"COMADMIN_E_CANTCOPYFILE";
            case -0x7feefbf1:
              return L"COMADMIN_E_NOUSER";
            case -0x7feefbf0:
              return L"COMADMIN_E_INVALIDUSERIDS";
            case -0x7feefbef:
              return L"COMADMIN_E_NOREGISTRYCLSID";
            case -0x7feefbee:
              return L"COMADMIN_E_BADREGISTRYPROGID";
            case -0x7feefbed:
              return L"COMADMIN_E_AUTHENTICATIONLEVEL";
            case -0x7feefbec:
              return L"COMADMIN_E_USERPASSWDNOTVALID";
            case -0x7feefbe8:
              return L"COMADMIN_E_CLSIDORIIDMISMATCH";
            case -0x7feefbe7:
              return L"COMADMIN_E_REMOTEINTERFACE";
            case -0x7feefbe6:
              return L"COMADMIN_E_DLLREGISTERSERVER";
            case -0x7feefbe5:
              return L"COMADMIN_E_NOSERVERSHARE";
            case -0x7feefbe3:
              return L"COMADMIN_E_DLLLOADFAILED";
            }
          }
        }
        else if (param_1 < -0x7feefba4) {
          if (param_1 == -0x7feefba5) {
            return L"COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED";
          }
          switch(param_1) {
          case -0x7feefbe1:
            return L"COMADMIN_E_APPDIRNOTFOUND";
          case -0x7feefbdd:
            return L"COMADMIN_E_REGISTRARFAILED";
          case -0x7feefbdc:
            return L"COMADMIN_E_COMPFILE_DOESNOTEXIST";
          case -0x7feefbdb:
            return L"COMADMIN_E_COMPFILE_LOADDLLFAIL";
          case -0x7feefbda:
            return L"COMADMIN_E_COMPFILE_GETCLASSOBJ";
          case -0x7feefbd9:
            return L"COMADMIN_E_COMPFILE_CLASSNOTAVAIL";
          case -0x7feefbd8:
            return L"COMADMIN_E_COMPFILE_BADTLB";
          case -0x7feefbd7:
            return L"COMADMIN_E_COMPFILE_NOTINSTALLABLE";
          case -0x7feefbd6:
            return L"COMADMIN_E_NOTCHANGEABLE";
          case -0x7feefbd5:
            return L"COMADMIN_E_NOTDELETEABLE";
          case -0x7feefbd4:
            return L"COMADMIN_E_SESSION";
          case -0x7feefbd3:
            return L"COMADMIN_E_COMP_MOVE_LOCKED";
          case -0x7feefbd2:
            return L"COMADMIN_E_COMP_MOVE_BAD_DEST";
          case -0x7feefbd0:
            return L"COMADMIN_E_REGISTERTLB";
          case -0x7feefbcd:
            return L"COMADMIN_E_SYSTEMAPP";
          case -0x7feefbcc:
            return L"COMADMIN_E_COMPFILE_NOREGISTRAR";
          case -0x7feefbcb:
            return L"COMADMIN_E_COREQCOMPINSTALLED";
          case -0x7feefbca:
            return L"COMADMIN_E_SERVICENOTINSTALLED";
          case -0x7feefbc9:
            return L"COMADMIN_E_PROPERTYSAVEFAILED";
          case -0x7feefbc8:
            return L"COMADMIN_E_OBJECTEXISTS";
          case -0x7feefbc7:
            return L"COMADMIN_E_COMPONENTEXISTS";
          case -0x7feefbc5:
            return L"COMADMIN_E_REGFILE_CORRUPT";
          case -0x7feefbc4:
            return L"COMADMIN_E_PROPERTY_OVERFLOW";
          case -0x7feefbc2:
            return L"COMADMIN_E_NOTINREGISTRY";
          case -0x7feefbc1:
            return L"COMADMIN_E_OBJECTNOTPOOLABLE";
          case -0x7feefbba:
            return L"COMADMIN_E_APPLID_MATCHES_CLSID";
          case -0x7feefbb9:
            return L"COMADMIN_E_ROLE_DOES_NOT_EXIST";
          case -0x7feefbb8:
            return L"COMADMIN_E_START_APP_NEEDS_COMPONENTS";
          case -0x7feefbb7:
            return L"COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM";
          case -0x7feefbb6:
            return L"COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY";
          case -0x7feefbb5:
            return L"COMADMIN_E_CAN_NOT_START_APP";
          case -0x7feefbb4:
            return L"COMADMIN_E_CAN_NOT_EXPORT_SYS_APP";
          case -0x7feefbb3:
            return L"COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT";
          case -0x7feefbb2:
            return L"COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER";
          case -0x7feefbb1:
            return L"COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE";
          case -0x7feefbb0:
            return L"COMADMIN_E_BASE_PARTITION_ONLY";
          case -0x7feefbaf:
            return L"COMADMIN_E_START_APP_DISABLED";
          case -0x7feefba9:
            return L"COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME";
          case -0x7feefba8:
            return L"COMADMIN_E_CAT_INVALID_PARTITION_NAME";
          case -0x7feefba7:
            return L"COMADMIN_E_CAT_PARTITION_IN_USE";
          case -0x7feefba6:
            return L"COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES";
          }
        }
        else if (param_1 < -0x7feef8fe) {
          if (param_1 == -0x7feef8ff) {
            return L"MSDTC_E_DUPLICATE_RESOURCE";
          }
          if (param_1 < -0x7feefb7b) {
            if (param_1 == -0x7feefb7c) {
              return L"COMADMIN_E_CAT_WRONGAPPBITNESS";
            }
            if (param_1 < -0x7feefb8a) {
              if (param_1 == -0x7feefb8b) {
                return L"COMADMIN_E_REGDB_ALREADYRUNNING";
              }
              if (param_1 == -0x7feefba4) {
                return L"COMADMIN_E_AMBIGUOUS_APPLICATION_NAME";
              }
              if (param_1 == -0x7feefba3) {
                return L"COMADMIN_E_AMBIGUOUS_PARTITION_NAME";
              }
              if (param_1 == -0x7feefb8e) {
                return L"COMADMIN_E_REGDB_NOTINITIALIZED";
              }
              if (param_1 == -0x7feefb8d) {
                return L"COMADMIN_E_REGDB_NOTOPEN";
              }
              if (param_1 == -0x7feefb8c) {
                return L"COMADMIN_E_REGDB_SYSTEMERR";
              }
            }
            else {
              if (param_1 == -0x7feefb80) {
                return L"COMADMIN_E_MIG_VERSIONNOTSUPPORTED";
              }
              if (param_1 == -0x7feefb7f) {
                return L"COMADMIN_E_MIG_SCHEMANOTFOUND";
              }
              if (param_1 == -0x7feefb7e) {
                return L"COMADMIN_E_CAT_BITNESSMISMATCH";
              }
              if (param_1 == -0x7feefb7d) {
                return L"COMADMIN_E_CAT_UNACCEPTABLEBITNESS";
              }
            }
          }
          else if (param_1 < -0x7feef9fd) {
            if (param_1 == -0x7feef9fe) {
              return L"COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE";
            }
            if (param_1 == -0x7feefb7b) {
              return L"COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED";
            }
            if (param_1 == -0x7feefb7a) {
              return L"COMADMIN_E_CAT_SERVERFAULT";
            }
            if (param_1 == -0x7feefa00) {
              return L"COMQC_E_APPLICATION_NOT_QUEUED";
            }
            if (param_1 == -0x7feef9ff) {
              return L"COMQC_E_NO_QUEUEABLE_INTERFACES";
            }
          }
          else {
            if (param_1 == -0x7feef9fd) {
              return L"COMQC_E_NO_IPERSISTSTREAM";
            }
            if (param_1 == -0x7feef9fc) {
              return L"COMQC_E_BAD_MESSAGE";
            }
            if (param_1 == -0x7feef9fb) {
              return L"COMQC_E_UNAUTHENTICATED";
            }
            if (param_1 == -0x7feef9fa) {
              return L"COMQC_E_UNTRUSTED_ENQUEUER";
            }
          }
        }
        else {
          switch(param_1) {
          case -0x7feef7f8:
            return L"COMADMIN_E_OBJECT_PARENT_MISSING";
          case -0x7feef7f7:
            return L"COMADMIN_E_OBJECT_DOES_NOT_EXIST";
          case -0x7feef7f6:
            return L"COMADMIN_E_APP_NOT_RUNNING";
          case -0x7feef7f5:
            return L"COMADMIN_E_INVALID_PARTITION";
          case -0x7feef7f3:
            return L"COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE";
          case -0x7feef7f2:
            return L"COMADMIN_E_USER_IN_SET";
          case -0x7feef7f1:
            return L"COMADMIN_E_CANTRECYCLELIBRARYAPPS";
          case -0x7feef7ef:
            return L"COMADMIN_E_CANTRECYCLESERVICEAPPS";
          case -0x7feef7ee:
            return L"COMADMIN_E_PROCESSALREADYRECYCLED";
          case -0x7feef7ed:
            return L"COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED";
          case -0x7feef7ec:
            return L"COMADMIN_E_CANTMAKEINPROCSERVICE";
          case -0x7feef7eb:
            return L"COMADMIN_E_PROGIDINUSEBYCLSID";
          case -0x7feef7ea:
            return L"COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET";
          case -0x7feef7e9:
            return L"COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED";
          case -0x7feef7e8:
            return L"COMADMIN_E_PARTITION_ACCESSDENIED";
          case -0x7feef7e7:
            return L"COMADMIN_E_PARTITION_MSI_ONLY";
          case -0x7feef7e6:
            return L"COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT";
          case -0x7feef7e5:
            return L"COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS";
          case -0x7feef7e4:
            return L"COMADMIN_E_COMP_MOVE_SOURCE";
          case -0x7feef7e3:
            return L"COMADMIN_E_COMP_MOVE_DEST";
          }
        }
      }
      else if (param_1 < -0x7789fe1f) {
        if (param_1 == -0x7789fe20) {
          return L"DDERR_TOOBIGSIZE";
        }
        if (param_1 < -0x7fea7c9f) {
          if (param_1 == -0x7fea7ca0) {
            return L"DPNERR_INVALIDHANDLE";
          }
          if (param_1 < -0x7feafe75) {
            if (param_1 == -0x7feafe76) {
              return L"DVERR_TRANSPORTNOTINIT";
            }
            if (param_1 < -0x7feafe8e) {
              if (param_1 == -0x7feafe8f) {
                return L"DVERR_TRANSPORTNOTHOST";
              }
              if (param_1 < -0x7feaff6e) {
                if (param_1 == -0x7feaff6f) {
                  return L"DVERR_INVALIDGROUP";
                }
                if (param_1 < -0x7feaffe1) {
                  if (param_1 == -0x7feaffe2) {
                    return L"DVERR_BUFFERTOOSMALL";
                  }
                  if (param_1 == -0x7feef7e1) {
                    return L"COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET";
                  }
                  if (param_1 == -0x7feef7e0) {
                    return L"COMADMIN_E_CANNOT_ALIAS_EVENTCLASS";
                  }
                  if (param_1 == -0x7feef7df) {
                    return L"COMADMIN_E_PRIVATE_ACCESSDENIED";
                  }
                  if (param_1 == -0x7feef7de) {
                    return L"COMADMIN_E_SAFERINVALID";
                  }
                  if (param_1 == -0x7feef7dd) {
                    return L"COMADMIN_E_REGISTRY_ACCESSDENIED";
                  }
                }
                else {
                  if (param_1 == -0x7feaffb6) {
                    return L"DVERR_EXCEPTION";
                  }
                  if (param_1 == -0x7feaff88) {
                    return L"DVERR_INVALIDFLAGS";
                  }
                  if (param_1 == -0x7feaff7e) {
                    return L"DVERR_INVALIDOBJECT";
                  }
                  if (param_1 == -0x7feaff79) {
                    return L"DVERR_INVALIDPLAYER";
                  }
                }
              }
              else if (param_1 < -0x7feafe95) {
                if (param_1 == -0x7feafe96) {
                  return L"DVERR_CONNECTED";
                }
                if (param_1 == -0x7feaff6a) {
                  return L"DVERR_INVALIDHANDLE";
                }
                if (param_1 == -0x7feafed4) {
                  return L"DVERR_SESSIONLOST";
                }
                if (param_1 == -0x7feafed2) {
                  return L"DVERR_NOVOICESESSION";
                }
                if (param_1 == -0x7feafe98) {
                  return L"DVERR_CONNECTIONLOST";
                }
                if (param_1 == -0x7feafe97) {
                  return L"DVERR_NOTINITIALIZED";
                }
              }
              else {
                if (param_1 == -0x7feafe95) {
                  return L"DVERR_NOTCONNECTED";
                }
                if (param_1 == -0x7feafe92) {
                  return L"DVERR_CONNECTABORTING";
                }
                if (param_1 == -0x7feafe91) {
                  return L"DVERR_NOTALLOWED";
                }
                if (param_1 == -0x7feafe90) {
                  return L"DVERR_INVALIDTARGET";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7feafe8e:
                return L"DVERR_COMPRESSIONNOTSUPPORTED";
              case -0x7feafe8d:
                return L"DVERR_ALREADYPENDING";
              case -0x7feafe8c:
                return L"DVERR_SOUNDINITFAILURE";
              case -0x7feafe8b:
                return L"DVERR_TIMEOUT";
              case -0x7feafe8a:
                return L"DVERR_CONNECTABORTED";
              case -0x7feafe89:
                return L"DVERR_NO3DSOUND";
              case -0x7feafe88:
                return L"DVERR_ALREADYBUFFERED";
              case -0x7feafe87:
                return L"DVERR_NOTBUFFERED";
              case -0x7feafe86:
                return L"DVERR_HOSTING";
              case -0x7feafe85:
                return L"DVERR_NOTHOSTING";
              case -0x7feafe84:
                return L"DVERR_INVALIDDEVICE";
              case -0x7feafe83:
                return L"DVERR_RECORDSYSTEMERROR";
              case -0x7feafe82:
                return L"DVERR_PLAYBACKSYSTEMERROR";
              case -0x7feafe81:
                return L"DVERR_SENDERROR";
              case -0x7feafe80:
                return L"DVERR_USERCANCEL";
              case -0x7feafe7d:
                return L"DVERR_RUNSETUP";
              case -0x7feafe7c:
                return L"DVERR_INCOMPATIBLEVERSION";
              case -0x7feafe79:
                return L"DVERR_INITIALIZED";
              case -0x7feafe78:
                return L"DVERR_NOTRANSPORT";
              case -0x7feafe77:
                return L"DVERR_NOCALLBACK";
              }
            }
          }
          else if (param_1 < -0x7fea7e8f) {
            if (param_1 == -0x7fea7e90) {
              return L"DPNERR_CONVERSION";
            }
            if (param_1 < -0x7fea7f8f) {
              if (param_1 == -0x7fea7f90) {
                return L"DPNERR_ALREADYDISCONNECTING";
              }
              if (param_1 < -0x7feafe6f) {
                if (param_1 == -0x7feafe70) {
                  return L"DVERR_LOCKEDBUFFER";
                }
                if (param_1 == -0x7feafe75) {
                  return L"DVERR_TRANSPORTNOSESSION";
                }
                if (param_1 == -0x7feafe74) {
                  return L"DVERR_TRANSPORTNOPLAYER";
                }
                if (param_1 == -0x7feafe73) {
                  return L"DVERR_USERBACK";
                }
                if (param_1 == -0x7feafe72) {
                  return L"DVERR_NORECVOLAVAILABLE";
                }
                if (param_1 == -0x7feafe71) {
                  return L"DVERR_INVALIDBUFFER";
                }
              }
              else {
                if (param_1 == -0x7fea7fd0) {
                  return L"DPNERR_ABORTED";
                }
                if (param_1 == -0x7fea7fc0) {
                  return L"DPNERR_ADDRESSING";
                }
                if (param_1 == -0x7fea7fb0) {
                  return L"DPNERR_ALREADYCLOSING";
                }
                if (param_1 == -0x7fea7fa0) {
                  return L"DPNERR_ALREADYCONNECTED";
                }
              }
            }
            else if (param_1 < -0x7fea7edf) {
              if (param_1 == -0x7fea7ee0) {
                return L"DPNERR_CANTCREATEGROUP";
              }
              if (param_1 == -0x7fea7f80) {
                return L"DPNERR_ALREADYINITIALIZED";
              }
              if (param_1 == -0x7fea7f70) {
                return L"DPNERR_ALREADYREGISTERED";
              }
              if (param_1 == -0x7fea7f00) {
                return L"DPNERR_BUFFERTOOSMALL";
              }
              if (param_1 == -0x7fea7ef0) {
                return L"DPNERR_CANNOTCANCEL";
              }
            }
            else {
              if (param_1 == -0x7fea7ed0) {
                return L"DPNERR_CANTCREATEPLAYER";
              }
              if (param_1 == -0x7fea7ec0) {
                return L"DPNERR_CANTLAUNCHAPPLICATION";
              }
              if (param_1 == -0x7fea7eb0) {
                return L"DPNERR_CONNECTING";
              }
              if (param_1 == -0x7fea7ea0) {
                return L"DPNERR_CONNECTIONLOST";
              }
            }
          }
          else if (param_1 < -0x7fea7d9f) {
            if (param_1 == -0x7fea7da0) {
              return L"DPNERR_HOSTREJECTEDCONNECTION";
            }
            if (param_1 < -0x7fea7def) {
              if (param_1 == -0x7fea7df0) {
                return L"DPNERR_ENUMQUERYTOOLARGE";
              }
              if (param_1 == -0x7fea7e8b) {
                return L"DPNERR_DATATOOLARGE";
              }
              if (param_1 == -0x7fea7e80) {
                return L"DPNERR_DOESNOTEXIST";
              }
              if (param_1 == -0x7fea7e7b) {
                return L"DPNERR_DPNSVRNOTAVAILABLE";
              }
              if (param_1 == -0x7fea7e70) {
                return L"DPNERR_DUPLICATECOMMAND";
              }
              if (param_1 == -0x7fea7e00) {
                return L"DPNERR_ENDPOINTNOTRECEIVING";
              }
            }
            else {
              if (param_1 == -0x7fea7de0) {
                return L"DPNERR_ENUMRESPONSETOOLARGE";
              }
              if (param_1 == -0x7fea7dd0) {
                return L"DPNERR_EXCEPTION";
              }
              if (param_1 == -0x7fea7dc0) {
                return L"DPNERR_GROUPNOTEMPTY";
              }
              if (param_1 == -0x7fea7db0) {
                return L"DPNERR_HOSTING";
              }
            }
          }
          else if (param_1 < -0x7fea7cef) {
            if (param_1 == -0x7fea7cf0) {
              return L"DPNERR_INVALIDCOMMAND";
            }
            if (param_1 == -0x7fea7d90) {
              return L"DPNERR_HOSTTERMINATEDSESSION";
            }
            if (param_1 == -0x7fea7d80) {
              return L"DPNERR_INCOMPLETEADDRESS";
            }
            if (param_1 == -0x7fea7d70) {
              return L"DPNERR_INVALIDADDRESSFORMAT";
            }
            if (param_1 == -0x7fea7d00) {
              return L"DPNERR_INVALIDAPPLICATION";
            }
          }
          else {
            if (param_1 == -0x7fea7ce0) {
              return L"DPNERR_INVALIDDEVICEADDRESS";
            }
            if (param_1 == -0x7fea7cd0) {
              return L"DPNERR_INVALIDENDPOINT";
            }
            if (param_1 == -0x7fea7cc0) {
              return L"DPNERR_INVALIDFLAGS";
            }
            if (param_1 == -0x7fea7cb0) {
              return L"DPNERR_INVALIDGROUP";
            }
          }
        }
        else if (param_1 < -0x7789ff5f) {
          if (param_1 == -0x7789ff60) {
            return L"DDERR_LOCKEDSURFACES";
          }
          if (param_1 < -0x7fea7a7f) {
            if (param_1 == -0x7fea7a80) {
              return L"DPNERR_PLAYERNOTINGROUP";
            }
            if (param_1 < -0x7fea7b8f) {
              if (param_1 == -0x7fea7b90) {
                return L"DPNERR_NOCAPS";
              }
              if (param_1 < -0x7fea7bdf) {
                if (param_1 == -0x7fea7be0) {
                  return L"DPNERR_INVALIDPLAYER";
                }
                if (param_1 == -0x7fea7c90) {
                  return L"DPNERR_INVALIDHOSTADDRESS";
                }
                if (param_1 == -0x7fea7c80) {
                  return L"DPNERR_INVALIDINSTANCE";
                }
                if (param_1 == -0x7fea7c70) {
                  return L"DPNERR_INVALIDINTERFACE";
                }
                if (param_1 == -0x7fea7c00) {
                  return L"DPNERR_INVALIDOBJECT";
                }
                if (param_1 == -0x7fea7bf0) {
                  return L"DPNERR_INVALIDPASSWORD";
                }
              }
              else {
                if (param_1 == -0x7fea7bd0) {
                  return L"DPNERR_INVALIDPRIORITY";
                }
                if (param_1 == -0x7fea7bc0) {
                  return L"DPNERR_INVALIDSTRING";
                }
                if (param_1 == -0x7fea7bb0) {
                  return L"DPNERR_INVALIDURL";
                }
                if (param_1 == -0x7fea7ba0) {
                  return L"DPNERR_INVALIDVERSION";
                }
              }
            }
            else if (param_1 < -0x7fea7acf) {
              if (param_1 == -0x7fea7ad0) {
                return L"DPNERR_NOTHOST";
              }
              if (param_1 == -0x7fea7b80) {
                return L"DPNERR_NOCONNECTION";
              }
              if (param_1 == -0x7fea7b70) {
                return L"DPNERR_NOHOSTPLAYER";
              }
              if (param_1 == -0x7fea7b00) {
                return L"DPNERR_NOMOREADDRESSCOMPONENTS";
              }
              if (param_1 == -0x7fea7af0) {
                return L"DPNERR_NORESPONSE";
              }
              if (param_1 == -0x7fea7ae0) {
                return L"DPNERR_NOTALLOWED";
              }
            }
            else {
              if (param_1 == -0x7fea7ac0) {
                return L"DPNERR_NOTREADY";
              }
              if (param_1 == -0x7fea7ab0) {
                return L"DPNERR_NOTREGISTERED";
              }
              if (param_1 == -0x7fea7aa0) {
                return L"DPNERR_PLAYERALREADYINGROUP";
              }
              if (param_1 == -0x7fea7a90) {
                return L"DPNERR_PLAYERLOST";
              }
            }
          }
          else if (param_1 < -0x7789ffd7) {
            if (param_1 == -0x7789ffd8) {
              return L"DDERR_CURRENTLYNOTAVAIL";
            }
            if (param_1 < -0x7fea79bf) {
              if (param_1 == -0x7fea79c0) {
                return L"DPNERR_UNINITIALIZED";
              }
              if (param_1 == -0x7fea7a70) {
                return L"DPNERR_PLAYERNOTREACHABLE";
              }
              if (param_1 == -0x7fea7a00) {
                return L"DPNERR_SENDTOOLARGE";
              }
              if (param_1 == -0x7fea79f0) {
                return L"DPNERR_SESSIONFULL";
              }
              if (param_1 == -0x7fea79e0) {
                return L"DPNERR_TABLEFULL";
              }
              if (param_1 == -0x7fea79d0) {
                return L"DPNERR_TIMEDOUT";
              }
            }
            else {
              if (param_1 == -0x7fea79b0) {
                return L"DPNERR_USERCANCEL";
              }
              if (param_1 == -0x7789fffb) {
                return L"DDERR_ALREADYINITIALIZED";
              }
              if (param_1 == -0x7789fff6) {
                return L"DDERR_CANNOTATTACHSURFACE";
              }
              if (param_1 == -0x7789ffec) {
                return L"DDERR_CANNOTDETACHSURFACE";
              }
            }
          }
          else if (param_1 < -0x7789ff91) {
            if (param_1 == -0x7789ff92) {
              return L"DDERR_INVALIDCLIPLIST";
            }
            if (param_1 == -0x7789ffc9) {
              return L"DDERR_EXCEPTION";
            }
            if (param_1 == -0x7789ffa6) {
              return L"DDERR_HEIGHTALIGN";
            }
            if (param_1 == -0x7789ffa1) {
              return L"DDERR_INCOMPATIBLEPRIMARY";
            }
            if (param_1 == -0x7789ff9c) {
              return L"DDERR_INVALIDCAPS";
            }
          }
          else {
            if (param_1 == -0x7789ff88) {
              return L"DDERR_INVALIDMODE";
            }
            if (param_1 == -0x7789ff7e) {
              return L"DDERR_INVALIDOBJECT";
            }
            if (param_1 == -0x7789ff6f) {
              return L"DDERR_INVALIDPIXELFORMAT";
            }
            if (param_1 == -0x7789ff6a) {
              return L"DDERR_INVALIDRECT";
            }
          }
        }
        else if (param_1 < -0x7789fec3) {
          if (param_1 == -0x7789fec4) {
            return L"DDERR_NOT4BITCOLOR";
          }
          if (param_1 < -0x7789ff1e) {
            if (param_1 == -0x7789ff1f) {
              return L"DDERR_NOEXCLUSIVEMODE";
            }
            if (param_1 < -0x7789ff2d) {
              if (param_1 == -0x7789ff2e) {
                return L"DDERR_NOCOLORCONVHW";
              }
              if (param_1 == -0x7789ff56) {
                return L"DDERR_NO3D";
              }
              if (param_1 == -0x7789ff4c) {
                return L"DDERR_NOALPHAHW";
              }
              if (param_1 == -0x7789ff4b) {
                return L"DDERR_NOSTEREOHARDWARE";
              }
              if (param_1 == -0x7789ff4a) {
                return L"DDERR_NOSURFACELEFT";
              }
              if (param_1 == -0x7789ff33) {
                return L"DDERR_NOCLIPLIST";
              }
            }
            else {
              if (param_1 == -0x7789ff2c) {
                return L"DDERR_NOCOOPERATIVELEVELSET";
              }
              if (param_1 == -0x7789ff29) {
                return L"DDERR_NOCOLORKEY";
              }
              if (param_1 == -0x7789ff24) {
                return L"DDERR_NOCOLORKEYHW";
              }
              if (param_1 == -0x7789ff22) {
                return L"DDERR_NODIRECTDRAWSUPPORT";
              }
            }
          }
          else if (param_1 < -0x7789fefb) {
            if (param_1 == -0x7789fefc) {
              return L"DDERR_NOOVERLAYHW";
            }
            if (param_1 == -0x7789ff1a) {
              return L"DDERR_NOFLIPHW";
            }
            if (param_1 == -0x7789ff10) {
              return L"DDERR_NOGDI";
            }
            if (param_1 == -0x7789ff06) {
              return L"DDERR_NOMIRRORHW";
            }
            if (param_1 == -0x7789ff01) {
              return L"DDERR_NOTFOUND";
            }
          }
          else {
            if (param_1 == -0x7789fef2) {
              return L"DDERR_OVERLAPPINGRECTS";
            }
            if (param_1 == -0x7789fee8) {
              return L"DDERR_NORASTEROPHW";
            }
            if (param_1 == -0x7789fede) {
              return L"DDERR_NOROTATIONHW";
            }
            if (param_1 == -0x7789feca) {
              return L"DDERR_NOSTRETCHHW";
            }
          }
        }
        else if (param_1 < -0x7789fe7c) {
          if (param_1 == -0x7789fe7d) {
            return L"DDERR_PALETTEBUSY";
          }
          if (param_1 < -0x7789fea1) {
            if (param_1 == -0x7789fea2) {
              return L"DDERR_NOZOVERLAYHW";
            }
            if (param_1 == -0x7789fec3) {
              return L"DDERR_NOT4BITCOLORINDEX";
            }
            if (param_1 == -0x7789fec0) {
              return L"DDERR_NOT8BITCOLOR";
            }
            if (param_1 == -0x7789feb6) {
              return L"DDERR_NOTEXTUREHW";
            }
            if (param_1 == -0x7789feb1) {
              return L"DDERR_NOVSYNCHW";
            }
            if (param_1 == -0x7789feac) {
              return L"DDERR_NOZBUFFERHW";
            }
          }
          else {
            if (param_1 == -0x7789fe98) {
              return L"DDERR_OUTOFCAPS";
            }
            if (param_1 == -0x7789fe84) {
              return L"D3DERR_OUTOFVIDEOMEMORY";
            }
            if (param_1 == -0x7789fe82) {
              return L"DDERR_OVERLAYCANTCLIP";
            }
            if (param_1 == -0x7789fe80) {
              return L"DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
            }
          }
        }
        else if (param_1 < -0x7789fe4c) {
          if (param_1 == -0x7789fe4d) {
            return L"DDERR_CANTLOCKSURFACE";
          }
          if (param_1 == -0x7789fe70) {
            return L"DDERR_COLORKEYNOTSET";
          }
          if (param_1 == -0x7789fe66) {
            return L"DDERR_SURFACEALREADYATTACHED";
          }
          if (param_1 == -0x7789fe5c) {
            return L"DDERR_SURFACEALREADYDEPENDENT";
          }
          if (param_1 == -0x7789fe52) {
            return L"DDERR_SURFACEBUSY";
          }
        }
        else {
          if (param_1 == -0x7789fe48) {
            return L"DDERR_SURFACEISOBSCURED";
          }
          if (param_1 == -0x7789fe3e) {
            return L"DDERR_SURFACELOST";
          }
          if (param_1 == -0x7789fe34) {
            return L"DDERR_SURFACENOTATTACHED";
          }
          if (param_1 == -0x7789fe2a) {
            return L"DDERR_TOOBIGHEIGHT";
          }
        }
      }
      else if (param_1 < -0x7789fc93) {
        if (param_1 == -0x7789fc94) {
          return L"DXFILEERR_NOINTERNET";
        }
        if (param_1 + 0x7789fe16U < 0x182) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(*(undefined1 *)(param_1 + 0x77fd6af7)) {
          case 0:
            return L"DDERR_TOOBIGWIDTH";
          case 1:
            return L"DDERR_UNSUPPORTEDFORMAT";
          case 2:
            return L"DDERR_UNSUPPORTEDMASK";
          case 3:
            return L"DDERR_INVALIDSTREAM";
          case 4:
            return L"DDERR_VERTICALBLANKINPROGRESS";
          case 5:
            return L"DDERR_WASSTILLDRAWING";
          case 6:
            return L"DDERR_DDSCAPSCOMPLEXREQUIRED";
          case 7:
            return L"DDERR_XALIGN";
          case 8:
            return L"DDERR_INVALIDDIRECTDRAWGUID";
          case 9:
            return L"DDERR_DIRECTDRAWALREADYCREATED";
          case 10:
            return L"DDERR_NODIRECTDRAWHW";
          case 0xb:
            return L"DDERR_PRIMARYSURFACEALREADYEXISTS";
          case 0xc:
            return L"DDERR_NOEMULATION";
          case 0xd:
            return L"DDERR_REGIONTOOSMALL";
          case 0xe:
            return L"DDERR_CLIPPERISUSINGHWND";
          case 0xf:
            return L"DDERR_NOCLIPPERATTACHED";
          case 0x10:
            return L"DDERR_NOHWND";
          case 0x11:
            return L"DDERR_HWNDSUBCLASSED";
          case 0x12:
            return L"DDERR_HWNDALREADYSET";
          case 0x13:
            return L"DDERR_NOPALETTEATTACHED";
          case 0x14:
            return L"DDERR_NOPALETTEHW";
          case 0x15:
            return L"DDERR_BLTFASTCANTCLIP";
          case 0x16:
            return L"DDERR_NOBLTHW";
          case 0x17:
            return L"DDERR_NODDROPSHW";
          case 0x18:
            return L"DDERR_OVERLAYNOTVISIBLE";
          case 0x19:
            return L"DDERR_NOOVERLAYDEST";
          case 0x1a:
            return L"DDERR_INVALIDPOSITION";
          case 0x1b:
            return L"DDERR_NOTAOVERLAYSURFACE";
          case 0x1c:
            return L"DDERR_EXCLUSIVEMODEALREADYSET";
          case 0x1d:
            return L"DDERR_NOTFLIPPABLE";
          case 0x1e:
            return L"DDERR_CANTDUPLICATE";
          case 0x1f:
            return L"DDERR_NOTLOCKED";
          case 0x20:
            return L"DDERR_CANTCREATEDC";
          case 0x21:
            return L"DDERR_NODC";
          case 0x22:
            return L"DDERR_WRONGMODE";
          case 0x23:
            return L"DDERR_IMPLICITLYCREATED";
          case 0x24:
            return L"DDERR_NOTPALETTIZED";
          case 0x25:
            return L"DDERR_UNSUPPORTEDMODE";
          case 0x26:
            return L"DDERR_NOMIPMAPHW";
          case 0x27:
            return L"DDERR_INVALIDSURFACETYPE";
          case 0x28:
            return L"DDERR_NOOPTIMIZEHW";
          case 0x29:
            return L"DDERR_NOTLOADED";
          case 0x2a:
            return L"DDERR_NOFOCUSWINDOW";
          case 0x2b:
            return L"DDERR_NOTONMIPMAPSUBLEVEL";
          case 0x2c:
            return L"DDERR_DCALREADYCREATED";
          case 0x2d:
            return L"DDERR_NONONLOCALVIDMEM";
          case 0x2e:
            return L"DDERR_CANTPAGELOCK";
          case 0x2f:
            return L"DDERR_CANTPAGEUNLOCK";
          case 0x30:
            return L"DDERR_NOTPAGELOCKED";
          case 0x31:
            return L"DDERR_MOREDATA";
          case 0x32:
            return L"DDERR_EXPIRED";
          case 0x33:
            return L"DDERR_TESTFINISHED";
          case 0x34:
            return L"DDERR_NEWMODE";
          case 0x35:
            return L"DDERR_D3DNOTINITIALIZED";
          case 0x36:
            return L"DDERR_VIDEONOTACTIVE";
          case 0x37:
            return L"DDERR_NOMONITORINFORMATION";
          case 0x38:
            return L"DDERR_NODRIVERSUPPORT";
          case 0x39:
            return L"DDERR_DEVICEDOESNTOWNSURFACE";
          case 0x3a:
            return L"DXFILEERR_BADOBJECT";
          case 0x3b:
            return L"DXFILEERR_BADVALUE";
          case 0x3c:
            return L"DXFILEERR_BADTYPE";
          case 0x3d:
            return L"DXFILEERR_BADSTREAMHANDLE";
          case 0x3e:
            return L"DXFILEERR_BADALLOC";
          case 0x3f:
            return L"DXFILEERR_NOTFOUND";
          case 0x40:
            return L"DXFILEERR_NOTDONEYET";
          case 0x41:
            return L"DXFILEERR_FILENOTFOUND";
          case 0x42:
            return L"DXFILEERR_RESOURCENOTFOUND";
          case 0x43:
            return L"DXFILEERR_URLNOTFOUND";
          case 0x44:
            return L"DXFILEERR_BADRESOURCE";
          case 0x45:
            return L"DXFILEERR_BADFILETYPE";
          case 0x46:
            return L"DXFILEERR_BADFILEVERSION";
          case 0x47:
            return L"DXFILEERR_BADFILEFLOATSIZE";
          case 0x48:
            return L"DXFILEERR_BADFILECOMPRESSIONTYPE";
          case 0x49:
            return L"DXFILEERR_BADFILE";
          case 0x4a:
            return L"DXFILEERR_PARSEERROR";
          case 0x4b:
            return L"DXFILEERR_NOTEMPLATE";
          case 0x4c:
            return L"DXFILEERR_BADARRAYSIZE";
          case 0x4d:
            return L"DXFILEERR_BADDATAREFERENCE";
          case 0x4e:
            return L"DXFILEERR_INTERNALERROR";
          case 0x4f:
            return L"DXFILEERR_NOMOREOBJECTS";
          case 0x50:
            return L"DXFILEERR_BADINTRINSICS";
          case 0x51:
            return L"DXFILEERR_NOMORESTREAMHANDLES";
          case 0x52:
            return L"DXFILEERR_NOMOREDATA";
          case 0x53:
            return L"DXFILEERR_BADCACHEFILE";
          }
        }
      }
      else if (param_1 < -0x7789f7e7) {
        if (param_1 == -0x7789f7e8) {
          return L"D3DERR_WRONGTEXTUREFORMAT";
        }
        switch(param_1) {
        case -0x7789fc7c:
          return L"D3DXFERR_BADOBJECT";
        case -0x7789fc7b:
          return L"D3DXFERR_BADVALUE";
        case -0x7789fc7a:
          return L"D3DXFERR_BADTYPE";
        case -0x7789fc79:
          return L"D3DXFERR_NOTFOUND";
        case -0x7789fc78:
          return L"D3DXFERR_NOTDONEYET";
        case -0x7789fc77:
          return L"D3DXFERR_FILENOTFOUND";
        case -0x7789fc76:
          return L"D3DXFERR_RESOURCENOTFOUND";
        case -0x7789fc75:
          return L"D3DXFERR_BADRESOURCE";
        case -0x7789fc74:
          return L"D3DXFERR_BADFILETYPE";
        case -0x7789fc73:
          return L"D3DXFERR_BADFILEVERSION";
        case -0x7789fc72:
          return L"D3DXFERR_BADFILEFLOATSIZE";
        case -0x7789fc71:
          return L"D3DXFERR_BADFILE";
        case -0x7789fc70:
          return L"D3DXFERR_PARSEERROR";
        case -0x7789fc6f:
          return L"D3DXFERR_BADARRAYSIZE";
        case -0x7789fc6e:
          return L"D3DXFERR_BADDATAREFERENCE";
        case -0x7789fc6d:
          return L"D3DXFERR_NOMOREOBJECTS";
        case -0x7789fc6c:
          return L"D3DXFERR_NOMOREDATA";
        case -0x7789fc6b:
          return L"D3DXFERR_BADCACHEFILE";
        }
      }
      else if (param_1 < -0x7789f799) {
        if (param_1 == -0x7789f79a) {
          return L"D3DERR_NOTFOUND";
        }
        switch(param_1) {
        case -0x7789f7e7:
          return L"D3DERR_UNSUPPORTEDCOLOROPERATION";
        case -0x7789f7e6:
          return L"D3DERR_UNSUPPORTEDCOLORARG";
        case -0x7789f7e5:
          return L"D3DERR_UNSUPPORTEDALPHAOPERATION";
        case -0x7789f7e4:
          return L"D3DERR_UNSUPPORTEDALPHAARG";
        case -0x7789f7e3:
          return L"D3DERR_TOOMANYOPERATIONS";
        case -0x7789f7e2:
          return L"D3DERR_CONFLICTINGTEXTUREFILTER";
        case -0x7789f7e1:
          return L"D3DERR_UNSUPPORTEDFACTORVALUE";
        case -0x7789f7df:
          return L"D3DERR_CONFLICTINGRENDERSTATE";
        case -0x7789f7de:
          return L"D3DERR_UNSUPPORTEDTEXTUREFILTER";
        case -0x7789f7da:
          return L"D3DERR_CONFLICTINGTEXTUREPALETTE";
        case -0x7789f7d9:
          return L"D3DERR_DRIVERINTERNALERROR";
        }
      }
      else if (param_1 < -0x7787ff4b) {
        if (param_1 == -0x7787ff4c) {
          return L"DSERR_BUFFERTOOSMALL";
        }
        if (param_1 < -0x7789f4a5) {
          if (param_1 == -0x7789f4a6) {
            return L"D3DXERR_LOADEDMESHASNODATA";
          }
          if (param_1 < -0x7789f792) {
            if (param_1 == -0x7789f793) {
              return L"D3DERR_DRIVERINVALIDCALL";
            }
            if (param_1 == -0x7789f799) {
              return L"D3DERR_MOREDATA";
            }
            if (param_1 == -0x7789f798) {
              return L"D3DERR_DEVICELOST";
            }
            if (param_1 == -0x7789f797) {
              return L"D3DERR_DEVICENOTRESET";
            }
            if (param_1 == -0x7789f796) {
              return L"D3DERR_NOTAVAILABLE";
            }
            if (param_1 == -0x7789f795) {
              return L"D3DERR_INVALIDDEVICE";
            }
            if (param_1 == -0x7789f794) {
              return L"D3DERR_INVALIDCALL";
            }
          }
          else {
            if (param_1 == -0x7789f4ac) {
              return L"D3DXERR_CANNOTMODIFYINDEXBUFFER";
            }
            if (param_1 == -0x7789f4ab) {
              return L"D3DXERR_INVALIDMESH";
            }
            if (param_1 == -0x7789f4aa) {
              return L"D3DXERR_CANNOTATTRSORT";
            }
            if (param_1 == -0x7789f4a9) {
              return L"D3DXERR_SKINNINGNOTSUPPORTED";
            }
            if (param_1 == -0x7789f4a8) {
              return L"D3DXERR_TOOMANYINFLUENCES";
            }
            if (param_1 == -0x7789f4a7) {
              return L"D3DXERR_INVALIDDATA";
            }
          }
        }
        else if (param_1 < -0x7787ff9b) {
          if (param_1 == -0x7787ff9c) {
            return L"DSERR_BADFORMAT";
          }
          if (param_1 == -0x7789f4a5) {
            return L"D3DXERR_DUPLICATENAMEDFRAGMENT";
          }
          if (param_1 == -0x7789f4a4) {
            return L"D3DXERR_CANNOTREMOVELASTITEM";
          }
          if (param_1 == -0x7787fff6) {
            return L"DSERR_ALLOCATED";
          }
          if (param_1 == -0x7787ffe2) {
            return L"DSERR_CONTROLUNAVAIL";
          }
          if (param_1 == -0x7787ffce) {
            return L"DSERR_INVALIDCALL";
          }
          if (param_1 == -0x7787ffba) {
            return L"DSERR_PRIOLEVELNEEDED";
          }
        }
        else {
          if (param_1 == -0x7787ff88) {
            return L"DSERR_NODRIVER";
          }
          if (param_1 == -0x7787ff7e) {
            return L"DSERR_ALREADYINITIALIZED";
          }
          if (param_1 == -0x7787ff6a) {
            return L"DSERR_BUFFERLOST";
          }
          if (param_1 == -0x7787ff60) {
            return L"DSERR_OTHERAPPHASPRIO";
          }
          if (param_1 == -0x7787ff56) {
            return L"DSERR_UNINITIALIZED";
          }
        }
      }
      else if (param_1 < -0x7787eeec) {
        if (param_1 == -0x7787eeed) {
          return L"DMUS_E_INVALIDPOS";
        }
        if (param_1 < -0x7787eefb) {
          if (param_1 == -0x7787eefc) {
            return L"DMUS_E_INSUFFICIENTBUFFER";
          }
          if (param_1 == -0x7787ff42) {
            return L"DSERR_DS8_REQUIRED";
          }
          if (param_1 == -0x7787ff38) {
            return L"DSERR_SENDLOOP";
          }
          if (param_1 == -0x7787ff2e) {
            return L"DSERR_BADSENDBUFFERGUID";
          }
          if (param_1 == -0x7787eeff) {
            return L"DMUS_E_DRIVER_FAILED";
          }
          if (param_1 == -0x7787eefe) {
            return L"DMUS_E_PORTS_OPEN";
          }
          if (param_1 == -0x7787eefd) {
            return L"DMUS_E_DEVICE_IN_USE";
          }
        }
        else {
          if (param_1 == -0x7787eefb) {
            return L"DMUS_E_BUFFERNOTSET";
          }
          if (param_1 == -0x7787eefa) {
            return L"DMUS_E_BUFFERNOTAVAILABLE";
          }
          if (param_1 == -0x7787eef8) {
            return L"DMUS_E_NOTADLSCOL";
          }
          if (param_1 == -0x7787eef7) {
            return L"DMUS_E_INVALIDOFFSET";
          }
          if (param_1 == -0x7787eeef) {
            return L"DMUS_E_ALREADY_LOADED";
          }
        }
      }
      else {
        switch(param_1) {
        case -0x7787eeec:
          return L"DMUS_E_INVALIDPATCH";
        case -0x7787eeeb:
          return L"DMUS_E_CANNOTSEEK";
        case -0x7787eeea:
          return L"DMUS_E_CANNOTWRITE";
        case -0x7787eee9:
          return L"DMUS_E_CHUNKNOTFOUND";
        case -0x7787eee7:
          return L"DMUS_E_INVALID_DOWNLOADID";
        case -0x7787eee0:
          return L"DMUS_E_NOT_DOWNLOADED_TO_PORT";
        case -0x7787eedf:
          return L"DMUS_E_ALREADY_DOWNLOADED";
        case -0x7787eede:
          return L"DMUS_E_UNKNOWN_PROPERTY";
        case -0x7787eedd:
          return L"DMUS_E_SET_UNSUPPORTED";
        case -0x7787eedc:
          return L"DMUS_E_GET_UNSUPPORTED";
        case -0x7787eedb:
          return L"DMUS_E_NOTMONO";
        case -0x7787eeda:
          return L"DMUS_E_BADARTICULATION";
        }
      }
    }
    else if (param_1 < -0x7787ee8f) {
      if (param_1 == -0x7787ee90) {
        return L"DMUS_E_NO_MASTER_CLOCK";
      }
      switch(param_1) {
      case -0x7787eed8:
        return L"DMUS_E_BADWAVELINK";
      case -0x7787eed7:
        return L"DMUS_E_NOARTICULATION";
      case -0x7787eed6:
        return L"DMUS_E_NOTPCM";
      case -0x7787eed5:
        return L"DMUS_E_BADWAVE";
      case -0x7787eed4:
        return L"DMUS_E_BADOFFSETTABLE";
      case -0x7787eed3:
        return L"DMUS_E_UNKNOWNDOWNLOAD";
      case -0x7787eed2:
        return L"DMUS_E_NOSYNTHSINK";
      case -0x7787eed1:
        return L"DMUS_E_ALREADYOPEN";
      case -0x7787eed0:
        return L"DMUS_E_ALREADYCLOSED";
      case -0x7787eecf:
        return L"DMUS_E_SYNTHNOTCONFIGURED";
      case -0x7787eece:
        return L"DMUS_E_SYNTHACTIVE";
      case -0x7787eecd:
        return L"DMUS_E_CANNOTREAD";
      case -0x7787eecc:
        return L"DMUS_E_DMUSIC_RELEASED";
      case -0x7787eecb:
        return L"DMUS_E_BUFFER_EMPTY";
      case -0x7787eeca:
        return L"DMUS_E_BUFFER_FULL";
      case -0x7787eec9:
        return L"DMUS_E_PORT_NOT_CAPTURE";
      case -0x7787eec8:
        return L"DMUS_E_PORT_NOT_RENDER";
      case -0x7787eec7:
        return L"DMUS_E_DSOUND_NOT_SET";
      case -0x7787eec6:
        return L"DMUS_E_ALREADY_ACTIVATED";
      case -0x7787eec5:
        return L"DMUS_E_INVALIDBUFFER";
      case -0x7787eec4:
        return L"DMUS_E_WAVEFORMATNOTSUPPORTED";
      case -0x7787eec3:
        return L"DMUS_E_SYNTHINACTIVE";
      case -0x7787eec2:
        return L"DMUS_E_DSOUND_ALREADY_SET";
      case -0x7787eec1:
        return L"DMUS_E_INVALID_EVENT";
      case -0x7787eeb0:
        return L"DMUS_E_UNSUPPORTED_STREAM";
      case -0x7787eeaf:
        return L"DMUS_E_ALREADY_INITED";
      case -0x7787eeae:
        return L"DMUS_E_INVALID_BAND";
      case -0x7787eeab:
        return L"DMUS_E_TRACK_HDR_NOT_FIRST_CK";
      case -0x7787eeaa:
        return L"DMUS_E_TOOL_HDR_NOT_FIRST_CK";
      case -0x7787eea9:
        return L"DMUS_E_INVALID_TRACK_HDR";
      case -0x7787eea8:
        return L"DMUS_E_INVALID_TOOL_HDR";
      case -0x7787eea7:
        return L"DMUS_E_ALL_TOOLS_FAILED";
      case -0x7787eea0:
        return L"DMUS_E_ALL_TRACKS_FAILED";
      case -0x7787ee9f:
        return L"DSERR_OBJECTNOTFOUND";
      case -0x7787ee9e:
        return L"DMUS_E_NOT_INIT";
      case -0x7787ee9d:
        return L"DMUS_E_TYPE_DISABLED";
      case -0x7787ee9c:
        return L"DMUS_E_TYPE_UNSUPPORTED";
      case -0x7787ee9b:
        return L"DMUS_E_TIME_PAST";
      case -0x7787ee9a:
        return L"DMUS_E_TRACK_NOT_FOUND";
      case -0x7787ee99:
        return L"DMUS_E_TRACK_NO_CLOCKTIME_SUPPORT";
      }
    }
    else if (param_1 < 0x427) {
      if (param_1 == 0x426) {
LAB_0072e8b3:
        return L"ERROR_SERVICE_NOT_ACTIVE";
      }
      if (param_1 < 0x6b) {
        if (param_1 == 0x6a) {
LAB_0072e1cb:
          return L"ERROR_SEM_USER_LIMIT";
        }
        if (param_1 < -0x3788f427) {
          if (param_1 == -0x3788f428) {
            return L"D3DXERR_ENUMFORMATSFAILED";
          }
          if (param_1 < -0x7787edd5) {
            if (param_1 == -0x7787edd6) {
              return L"DMUS_E_AUDIOPATH_NOBUFFER";
            }
            switch(param_1) {
            case -0x7787ee80:
              return L"DMUS_E_LOADER_NOCLASSID";
            case -0x7787ee7f:
              return L"DMUS_E_LOADER_BADPATH";
            case -0x7787ee7e:
              return L"DMUS_E_LOADER_FAILEDOPEN";
            case -0x7787ee7d:
              return L"DMUS_E_LOADER_FORMATNOTSUPPORTED";
            case -0x7787ee7c:
              return L"DMUS_E_LOADER_FAILEDCREATE";
            case -0x7787ee7b:
              return L"DMUS_E_LOADER_OBJECTNOTFOUND";
            case -0x7787ee7a:
              return L"DMUS_E_LOADER_NOFILENAME";
            case -0x7787ee00:
              return L"DMUS_E_INVALIDFILE";
            case -0x7787edff:
              return L"DMUS_E_ALREADY_EXISTS";
            case -0x7787edfe:
              return L"DMUS_E_OUT_OF_RANGE";
            case -0x7787edfd:
              return L"DMUS_E_SEGMENT_INIT_FAILED";
            case -0x7787edfc:
              return L"DMUS_E_ALREADY_SENT";
            case -0x7787edfb:
              return L"DMUS_E_CANNOT_FREE";
            case -0x7787edfa:
              return L"DMUS_E_CANNOT_OPEN_PORT";
            case -0x7787edf9:
              return L"DMUS_E_CANNOT_CONVERT";
            case -0x7787edf0:
              return L"DMUS_E_DESCEND_CHUNK_FAIL";
            case -0x7787edef:
              return L"DMUS_E_NOT_LOADED";
            case -0x7787eded:
              return L"DMUS_E_SCRIPT_LANGUAGE_INCOMPATIBLE";
            case -0x7787edec:
              return L"DMUS_E_SCRIPT_UNSUPPORTED_VARTYPE";
            case -0x7787edeb:
              return L"DMUS_E_SCRIPT_ERROR_IN_SCRIPT";
            case -0x7787edea:
              return L"DMUS_E_SCRIPT_CANTLOAD_OLEAUT32";
            case -0x7787ede9:
              return L"DMUS_E_SCRIPT_LOADSCRIPT_ERROR";
            case -0x7787ede8:
              return L"DMUS_E_SCRIPT_INVALID_FILE";
            case -0x7787ede7:
              return L"DMUS_E_INVALID_SCRIPTTRACK";
            case -0x7787ede6:
              return L"DMUS_E_SCRIPT_VARIABLE_NOT_FOUND";
            case -0x7787ede5:
              return L"DMUS_E_SCRIPT_ROUTINE_NOT_FOUND";
            case -0x7787ede4:
              return L"DMUS_E_SCRIPT_CONTENT_READONLY";
            case -0x7787ede3:
              return L"DMUS_E_SCRIPT_NOT_A_REFERENCE";
            case -0x7787ede2:
              return L"DMUS_E_SCRIPT_VALUE_NOT_SUPPORTED";
            case -0x7787ede0:
              return L"DMUS_E_INVALID_SEGMENTTRIGGERTRACK";
            case -0x7787eddf:
              return L"DMUS_E_INVALID_LYRICSTRACK";
            case -0x7787edde:
              return L"DMUS_E_INVALID_PARAMCONTROLTRACK";
            case -0x7787eddd:
              return L"DMUS_E_AUDIOVBSCRIPT_SYNTAXERROR";
            case -0x7787eddc:
              return L"DMUS_E_AUDIOVBSCRIPT_RUNTIMEERROR";
            case -0x7787eddb:
              return L"DMUS_E_AUDIOVBSCRIPT_OPERATIONFAILURE";
            case -0x7787edda:
              return L"DMUS_E_AUDIOPATHS_NOT_VALID";
            case -0x7787edd9:
              return L"DMUS_E_AUDIOPATHS_IN_USE";
            case -0x7787edd8:
              return L"DMUS_E_NO_AUDIOPATH_CONFIG";
            case -0x7787edd7:
              return L"DMUS_E_AUDIOPATH_INACTIVE";
            }
          }
          else if (param_1 < -0x3788f43b) {
            if (param_1 == -0x3788f43c) {
              return L"D3DXERR_INVALIDPARAMETER";
            }
            if (param_1 < -0x3788f445) {
              if (param_1 == -0x3788f446) {
                return L"D3DXERR_INVALIDD3DXDEVICEINDEX";
              }
              if (param_1 < -0x7787edd0) {
                if (param_1 == -0x7787edd1) {
                  return L"DMUS_E_INVALID_CONTAINER_OBJECT";
                }
                if (param_1 == -0x7787edd5) {
                  return L"DMUS_E_AUDIOPATH_NOPORT";
                }
                if (param_1 == -0x7787edd4) {
                  return L"DMUS_E_NO_AUDIOPATH";
                }
                if (param_1 == -0x7787edd3) {
                  return L"DMUS_E_INVALIDCHUNK";
                }
                if (param_1 == -0x7787edd2) {
                  return L"DMUS_E_AUDIOPATH_NOGLOBALFXBUFFER";
                }
              }
              else {
                if (param_1 == -0x3ff6ffff) {
                  return L"ERROR_AUDITING_DISABLED";
                }
                if (param_1 == -0x3ff6fffe) {
                  return L"ERROR_ALL_SIDS_FILTERED";
                }
                if (param_1 == -0x3788f448) {
                  return L"D3DXERR_NOMEMORY";
                }
                if (param_1 == -0x3788f447) {
                  return L"D3DXERR_NULLPOINTER";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x3788f445:
                return L"D3DXERR_NODIRECTDRAWAVAILABLE";
              case -0x3788f444:
                return L"D3DXERR_NODIRECT3DAVAILABLE";
              case -0x3788f443:
                return L"D3DXERR_NODIRECT3DDEVICEAVAILABLE";
              case -0x3788f442:
                return L"D3DXERR_NOPRIMARYAVAILABLE";
              case -0x3788f441:
                return L"D3DXERR_NOZBUFFERAVAILABLE";
              case -0x3788f440:
                return L"D3DXERR_NOBACKBUFFERAVAILABLE";
              case -0x3788f43f:
                return L"D3DXERR_COULDNTUPDATECAPS";
              case -0x3788f43e:
                return L"D3DXERR_NOZBUFFER";
              case -0x3788f43d:
                return L"D3DXERR_INVALIDMODE";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x3788f43b:
              return L"D3DXERR_INITFAILED";
            case -0x3788f43a:
              return L"D3DXERR_STARTUPFAILED";
            case -0x3788f439:
              return L"D3DXERR_D3DXNOTSTARTEDYET";
            case -0x3788f438:
              return L"D3DXERR_NOTINITIALIZED";
            case -0x3788f437:
              return L"D3DXERR_FAILEDDRAWTEXT";
            case -0x3788f436:
              return L"D3DXERR_BADD3DXCONTEXT";
            case -0x3788f435:
              return L"D3DXERR_CAPSNOTSUPPORTED";
            case -0x3788f434:
              return L"D3DXERR_UNSUPPORTEDFILEFORMAT";
            case -0x3788f433:
              return L"D3DXERR_IFLERROR";
            case -0x3788f432:
              return L"D3DXERR_FAILEDGETCAPS";
            case -0x3788f431:
              return L"D3DXERR_CANNOTRESIZEFULLSCREEN";
            case -0x3788f430:
              return L"D3DXERR_CANNOTRESIZENONWINDOWED";
            case -0x3788f42f:
              return L"D3DXERR_FRONTBUFFERALREADYEXISTS";
            case -0x3788f42e:
              return L"D3DXERR_FULLSCREENPRIMARYEXISTS";
            case -0x3788f42d:
              return L"D3DXERR_GETDCFAILED";
            case -0x3788f42c:
              return L"D3DXERR_BITBLTFAILED";
            case -0x3788f42b:
              return L"D3DXERR_NOTEXTURE";
            case -0x3788f42a:
              return L"D3DXERR_MIPLEVELABSENT";
            case -0x3788f429:
              return L"D3DXERR_SURFACENOTPALETTED";
            }
          }
        }
        else if (param_1 < 0x27) {
          if (param_1 == 0x26) goto LAB_0072df76;
          if (param_1 < 0x11) {
            if (param_1 == 0x10) goto LAB_0072de9b;
            if (param_1 < 7) {
              if (param_1 == 6) {
                return L"ERROR_INVALID_HANDLE";
              }
              if (param_1 < 2) {
                if (param_1 == 1) {
                  return L"S_FALSE";
                }
                if (param_1 == -0x3788f427) {
                  return L"D3DXERR_COLORDEPTHTOOLOW";
                }
                if (param_1 == -0x3788f426) {
                  return L"D3DXERR_INVALIDFILEFORMAT";
                }
                if (param_1 == -0x3788f425) {
                  return L"D3DXERR_NOMATCHFOUND";
                }
                if (param_1 == 0) {
                  return L"S_OK";
                }
              }
              else {
                if (param_1 == 2) goto LAB_00729b6b;
                if (param_1 == 3) goto LAB_0072de1a;
                if (param_1 == 4) goto LAB_0072de10;
                if (param_1 == 5) {
                  return L"ERROR_ACCESS_DENIED";
                }
              }
            }
            else {
              switch(param_1) {
              case 7:
                goto code_r0x0072de41;
              case 8:
                goto code_r0x0072de4b;
              case 9:
                goto code_r0x0072de55;
              case 10:
                goto code_r0x0072de5f;
              case 0xb:
                goto code_r0x0072de69;
              case 0xc:
                goto code_r0x0072de73;
              case 0xd:
                goto LAB_0072de7d;
              case 0xe:
                return L"ERROR_OUTOFMEMORY";
              case 0xf:
                goto code_r0x0072de91;
              }
            }
          }
          else {
            switch(param_1) {
            case 0x11:
              goto code_r0x0072deb8;
            case 0x12:
              goto code_r0x0072dec2;
            case 0x13:
              goto code_r0x0072decc;
            case 0x14:
              goto code_r0x0072ded6;
            case 0x15:
              goto code_r0x0072dee0;
            case 0x16:
              goto code_r0x0072deea;
            case 0x17:
              goto code_r0x0072def4;
            case 0x18:
              goto code_r0x0072defe;
            case 0x19:
              goto code_r0x0072df08;
            case 0x1a:
              goto code_r0x0072df12;
            case 0x1b:
              goto code_r0x0072df1c;
            case 0x1c:
              goto code_r0x0072df26;
            case 0x1d:
              goto code_r0x0072df30;
            case 0x1e:
              goto code_r0x0072df3a;
            case 0x1f:
              goto code_r0x0072df44;
            case 0x20:
              goto code_r0x0072df4e;
            case 0x21:
              goto code_r0x0072df58;
            case 0x22:
              goto code_r0x0072df62;
            case 0x24:
              goto code_r0x0072df6c;
            }
          }
        }
        else if (param_1 < 0x45) {
          if (param_1 == 0x44) goto LAB_0072e09c;
          if (param_1 < 0x3b) {
            if (param_1 == 0x3a) goto LAB_0072e025;
            if (param_1 < 0x36) {
              if (param_1 == 0x35) goto LAB_0072dfe1;
              if (param_1 == 0x27) goto LAB_0072dfd7;
              if (param_1 == 0x32) goto LAB_0072dfcd;
              if (param_1 == 0x33) goto LAB_0072dfc3;
              if (param_1 == 0x34) goto code_r0x0072dfb9;
            }
            else {
              if (param_1 == 0x36) goto LAB_0072e01b;
              if (param_1 == 0x37) goto LAB_0072e011;
              if (param_1 == 0x38) goto LAB_0072e007;
              if (param_1 == 0x39) goto code_r0x0072dffd;
            }
          }
          else {
            switch(param_1) {
            case 0x3b:
              goto code_r0x0072e042;
            case 0x3c:
              goto code_r0x0072e04c;
            case 0x3d:
              goto code_r0x0072e056;
            case 0x3e:
              goto code_r0x0072e060;
            case 0x3f:
              goto code_r0x0072e06a;
            case 0x40:
              goto code_r0x0072e074;
            case 0x41:
              goto LAB_0072e07e;
            case 0x42:
              goto code_r0x0072e088;
            case 0x43:
              goto code_r0x0072e092;
            }
          }
        }
        else if (param_1 < 0x57) {
          if (param_1 == 0x56) goto LAB_0072e13a;
          if (param_1 < 0x51) {
            if (param_1 == 0x50) goto LAB_0072e0f6;
            if (param_1 == 0x45) goto LAB_0072e0ec;
            if (param_1 == 0x46) goto LAB_0072e0e2;
            if (param_1 == 0x47) goto LAB_0072e0d8;
            if (param_1 == 0x48) goto code_r0x0072e0ce;
          }
          else {
            if (param_1 == 0x52) goto LAB_0072e130;
            if (param_1 == 0x53) goto LAB_0072e126;
            if (param_1 == 0x54) goto LAB_0072e11c;
            if (param_1 == 0x55) goto code_r0x0072e112;
          }
        }
        else if (param_1 < 0x66) {
          if (param_1 == 0x65) goto LAB_0072e187;
          if (param_1 == 0x57) {
            return L"ERROR_INVALID_PARAMETER";
          }
          if (param_1 == 0x58) goto LAB_0072e173;
          if (param_1 == 0x59) goto LAB_0072e169;
          if (param_1 == 100) goto code_r0x0072e15f;
        }
        else {
          if (param_1 == 0x66) goto LAB_0072e1c1;
          if (param_1 == 0x67) goto LAB_0072e1b7;
          if (param_1 == 0x68) goto LAB_0072e1ad;
          if (param_1 == 0x69) goto code_r0x0072e1a3;
        }
      }
      else if (param_1 < 0xf1) {
        if (param_1 == 0xf0) {
LAB_0072e5b1:
          return L"ERROR_VC_DISCONNECTED";
        }
        switch(param_1) {
        case 0x6b:
          goto code_r0x0072e1fb;
        case 0x6c:
          goto code_r0x0072e205;
        case 0x6d:
          goto code_r0x0072e20f;
        case 0x6e:
          goto code_r0x0072e219;
        case 0x6f:
          goto code_r0x0072e223;
        case 0x70:
          goto code_r0x0072e22d;
        case 0x71:
          goto code_r0x0072e237;
        case 0x72:
          goto code_r0x0072e241;
        case 0x75:
          goto code_r0x0072e24b;
        case 0x76:
          goto code_r0x0072e255;
        case 0x77:
          goto code_r0x0072e25f;
        case 0x78:
          goto code_r0x0072e269;
        case 0x79:
          goto code_r0x0072e273;
        case 0x7a:
          goto code_r0x0072e27d;
        case 0x7b:
          goto code_r0x0072e287;
        case 0x7c:
          goto code_r0x0072e291;
        case 0x7d:
          goto code_r0x0072e29b;
        case 0x7e:
          goto code_r0x0072e2a5;
        case 0x7f:
          goto code_r0x0072e2af;
        case 0x80:
          goto code_r0x0072e2b9;
        case 0x81:
          goto code_r0x0072e2c3;
        case 0x82:
          goto code_r0x0072e2cd;
        case 0x83:
          goto code_r0x0072e2d7;
        case 0x84:
          goto code_r0x0072e2e1;
        case 0x85:
          goto code_r0x0072e2eb;
        case 0x86:
          goto code_r0x0072e2f5;
        case 0x87:
          goto code_r0x0072e2ff;
        case 0x88:
          goto code_r0x0072e309;
        case 0x89:
          goto code_r0x0072e313;
        case 0x8a:
          goto code_r0x0072e31d;
        case 0x8b:
          goto code_r0x0072e327;
        case 0x8c:
          goto code_r0x0072e331;
        case 0x8d:
          goto code_r0x0072e33b;
        case 0x8e:
          goto code_r0x0072e345;
        case 0x8f:
          goto code_r0x0072e34f;
        case 0x90:
          goto code_r0x0072e359;
        case 0x91:
          goto code_r0x0072e363;
        case 0x92:
          goto code_r0x0072e36d;
        case 0x93:
          goto code_r0x0072e377;
        case 0x94:
          goto code_r0x0072e381;
        case 0x95:
          goto code_r0x0072e38b;
        case 0x96:
          goto code_r0x0072e395;
        case 0x97:
          goto code_r0x0072e39f;
        case 0x98:
          goto code_r0x0072e3a9;
        case 0x99:
          goto code_r0x0072e3b3;
        case 0x9a:
          goto code_r0x0072e3bd;
        case 0x9b:
          goto code_r0x0072e3c7;
        case 0x9c:
          goto code_r0x0072e3d1;
        case 0x9d:
          goto code_r0x0072e3db;
        case 0x9e:
          goto code_r0x0072e3e5;
        case 0x9f:
          goto code_r0x0072e3ef;
        case 0xa0:
          goto code_r0x0072e3f9;
        case 0xa1:
          goto code_r0x0072e403;
        case 0xa2:
          goto code_r0x0072e40d;
        case 0xa4:
          goto code_r0x0072e417;
        case 0xa7:
          goto code_r0x0072e421;
        case 0xaa:
          goto code_r0x0072e42b;
        case 0xad:
          goto LAB_0072e435;
        case 0xae:
code_r0x0072e43f:
          return L"ERROR_ATOMIC_LOCKS_NOT_SUPPORTED";
        case 0xb4:
code_r0x0072e449:
          return L"ERROR_INVALID_SEGMENT_NUMBER";
        case 0xb6:
code_r0x0072e453:
          return L"ERROR_INVALID_ORDINAL";
        case 0xb7:
code_r0x0072e45d:
          return L"ERROR_ALREADY_EXISTS";
        case 0xba:
code_r0x0072e467:
          return L"ERROR_INVALID_FLAG_NUMBER";
        case 0xbb:
code_r0x0072e471:
          return L"ERROR_SEM_NOT_FOUND";
        case 0xbc:
code_r0x0072e47b:
          return L"ERROR_INVALID_STARTING_CODESEG";
        case 0xbd:
code_r0x0072e485:
          return L"ERROR_INVALID_STACKSEG";
        case 0xbe:
code_r0x0072e48f:
          return L"ERROR_INVALID_MODULETYPE";
        case 0xbf:
code_r0x0072e499:
          return L"ERROR_INVALID_EXE_SIGNATURE";
        case 0xc0:
code_r0x0072e4a3:
          return L"ERROR_EXE_MARKED_INVALID";
        case 0xc1:
code_r0x0072e4ad:
          return L"ERROR_BAD_EXE_FORMAT";
        case 0xc2:
code_r0x0072e4b7:
          return L"ERROR_ITERATED_DATA_EXCEEDS_64k";
        case 0xc3:
code_r0x0072e4c1:
          return L"ERROR_INVALID_MINALLOCSIZE";
        case 0xc4:
code_r0x0072e4cb:
          return L"ERROR_DYNLINK_FROM_INVALID_RING";
        case 0xc5:
code_r0x0072e4d5:
          return L"ERROR_IOPL_NOT_ENABLED";
        case 0xc6:
code_r0x0072e4df:
          return L"ERROR_INVALID_SEGDPL";
        case 199:
code_r0x0072e4e9:
          return L"ERROR_AUTODATASEG_EXCEEDS_64k";
        case 200:
          return L"ERROR_RING2SEG_MUST_BE_MOVABLE";
        case 0xc9:
          return L"ERROR_RELOC_CHAIN_XEEDS_SEGLIM";
        case 0xca:
code_r0x0072e507:
          return L"ERROR_INFLOOP_IN_RELOC_CHAIN";
        case 0xcb:
code_r0x0072e511:
          return L"ERROR_ENVVAR_NOT_FOUND";
        case 0xcd:
code_r0x0072e51b:
          return L"ERROR_NO_SIGNAL_SENT";
        case 0xce:
code_r0x0072e525:
          return L"ERROR_FILENAME_EXCED_RANGE";
        case 0xcf:
code_r0x0072e52f:
          return L"ERROR_RING2_STACK_IN_USE";
        case 0xd0:
code_r0x0072e539:
          return L"ERROR_META_EXPANSION_TOO_LONG";
        case 0xd1:
code_r0x0072e543:
          return L"ERROR_INVALID_SIGNAL_NUMBER";
        case 0xd2:
code_r0x0072e54d:
          return L"ERROR_THREAD_1_INACTIVE";
        case 0xd4:
code_r0x0072e557:
          return L"ERROR_LOCKED";
        case 0xd6:
code_r0x0072e561:
          return L"ERROR_TOO_MANY_MODULES";
        case 0xd7:
code_r0x0072e56b:
          return L"ERROR_NESTING_NOT_ALLOWED";
        case 0xd8:
code_r0x0072e575:
          return L"ERROR_EXE_MACHINE_TYPE_MISMATCH";
        case 0xe6:
code_r0x0072e57f:
          return L"ERROR_BAD_PIPE";
        case 0xe7:
code_r0x0072e589:
          return L"ERROR_PIPE_BUSY";
        case 0xe8:
code_r0x0072e593:
          return L"ERROR_NO_DATA";
        case 0xe9:
code_r0x0072e59d:
          return L"ERROR_PIPE_NOT_CONNECTED";
        case 0xea:
code_r0x0072e5a7:
          return L"ERROR_MORE_DATA";
        }
      }
      else if (param_1 < 0x3ec) {
        if (param_1 == 0x3eb) {
LAB_0072e761:
          return L"ERROR_CAN_NOT_COMPLETE";
        }
        if (param_1 < 0x12e) {
          if (param_1 == 0x12d) {
LAB_0072e67f:
            return L"ERROR_INVALID_OPLOCK_PROTOCOL";
          }
          switch(param_1) {
          case 0xfe:
            goto code_r0x0072e5fd;
          case 0xff:
            goto code_r0x0072e607;
          case 0x102:
            goto code_r0x0072e611;
          case 0x103:
            goto code_r0x0072e61b;
          case 0x10a:
            goto LAB_0072e625;
          case 0x10b:
LAB_0072e62f:
            return L"ERROR_DIRECTORY";
          case 0x113:
LAB_0072e639:
            return L"ERROR_EAS_DIDNT_FIT";
          case 0x114:
LAB_0072e643:
            return L"ERROR_EA_FILE_CORRUPT";
          case 0x115:
code_r0x00729c93:
            return L"ERROR_EA_TABLE_FULL";
          case 0x116:
LAB_0072e64d:
            return L"ERROR_INVALID_EA_HANDLE";
          case 0x11a:
LAB_0072e657:
            return L"ERROR_EAS_NOT_SUPPORTED";
          case 0x120:
LAB_0072e661:
            return L"ERROR_NOT_OWNER";
          case 0x12a:
LAB_0072e66b:
            return L"ERROR_TOO_MANY_POSTS";
          case 299:
code_r0x00729cc9:
            return L"ERROR_PARTIAL_COPY";
          case 300:
            goto LAB_0072e675;
          }
        }
        else if (param_1 < 0x3e3) {
          if (param_1 == 0x3e2) {
LAB_00729d44:
            return L"ERROR_EA_ACCESS_DENIED";
          }
          if (param_1 == 0x12e) {
LAB_0072e6f3:
            return L"ERROR_DISK_TOO_FRAGMENTED";
          }
          if (param_1 == 0x12f) {
LAB_0072e6e9:
            return L"ERROR_DELETE_PENDING";
          }
          if (param_1 == 0x13d) {
LAB_00729d0e:
            return L"ERROR_MR_MID_NOT_FOUND";
          }
          if (param_1 == 0x1e7) goto LAB_0072e6df;
          if (param_1 == 0x216) goto LAB_0072e6d5;
          if (param_1 == 0x217) goto LAB_0072e6cb;
          if (param_1 == 0x218) goto LAB_0072e6c1;
        }
        else {
          if (param_1 == 0x3e3) goto LAB_0072e757;
          if (param_1 == 0x3e4) goto LAB_0072e74d;
          if (param_1 == 0x3e5) goto LAB_0072e743;
          if (param_1 == 0x3e6) goto LAB_0072e739;
          if (param_1 == 999) goto LAB_0072e72f;
          if (param_1 == 0x3e9) goto LAB_0072e725;
          if (param_1 == 0x3ea) goto code_r0x0072e71b;
        }
      }
      else {
        switch(param_1) {
        case 0x3ec:
LAB_0072e787:
          return L"ERROR_INVALID_FLAGS";
        case 0x3ed:
LAB_0072e791:
          return L"ERROR_UNRECOGNIZED_VOLUME";
        case 0x3ee:
LAB_0072e79b:
          return L"ERROR_FILE_INVALID";
        case 0x3ef:
LAB_0072e7a5:
          return L"ERROR_FULLSCREEN_MODE";
        case 0x3f0:
LAB_0072e7af:
          return L"ERROR_NO_TOKEN";
        case 0x3f1:
LAB_0072e7b9:
          return L"ERROR_BADDB";
        case 0x3f2:
LAB_0072e7c3:
          return L"ERROR_BADKEY";
        case 0x3f3:
LAB_0072e7cd:
          return L"ERROR_CANTOPEN";
        case 0x3f4:
LAB_0072e7d7:
          return L"ERROR_CANTREAD";
        case 0x3f5:
LAB_0072e7e1:
          return L"ERROR_CANTWRITE";
        case 0x3f6:
LAB_0072e7eb:
          return L"ERROR_REGISTRY_RECOVERED";
        case 0x3f7:
LAB_0072e7f5:
          return L"ERROR_REGISTRY_CORRUPT";
        case 0x3f8:
          goto LAB_0072e7ff;
        case 0x3f9:
          goto LAB_0072e809;
        case 0x3fa:
          goto LAB_0072e813;
        case 0x3fb:
          goto LAB_0072e81d;
        case 0x3fc:
          goto LAB_0072e827;
        case 0x3fd:
          goto LAB_0072e831;
        case 0x3fe:
          goto LAB_0072e83b;
        case 0x41b:
          goto LAB_0072e845;
        case 0x41c:
          goto LAB_0072e84f;
        case 0x41d:
          goto LAB_0072e859;
        case 0x41e:
          goto LAB_0072e863;
        case 0x41f:
          goto LAB_0072e86d;
        case 0x420:
          goto LAB_0072e877;
        case 0x421:
          goto LAB_0072e881;
        case 0x422:
          goto LAB_0072e88b;
        case 0x423:
          goto LAB_0072e895;
        case 0x424:
          goto LAB_0072e89f;
        case 0x425:
          goto LAB_0072e8a9;
        }
      }
    }
    else {
      switch(param_1) {
      case 0x427:
LAB_0072e8d4:
        return L"ERROR_FAILED_SERVICE_CONTROLLER_CONNECT";
      case 0x428:
LAB_0072e8de:
        return L"ERROR_EXCEPTION_IN_SERVICE";
      case 0x429:
LAB_0072e8e8:
        return L"ERROR_DATABASE_DOES_NOT_EXIST";
      case 0x42a:
LAB_0072e8f2:
        return L"ERROR_SERVICE_SPECIFIC_ERROR";
      case 0x42b:
LAB_0072e8fc:
        return L"ERROR_PROCESS_ABORTED";
      case 0x42c:
LAB_0072e906:
        return L"ERROR_SERVICE_DEPENDENCY_FAIL";
      case 0x42d:
LAB_0072e910:
        return L"ERROR_SERVICE_LOGON_FAILED";
      case 0x42e:
LAB_0072e91a:
        return L"ERROR_SERVICE_START_HANG";
      case 0x42f:
LAB_0072e924:
        return L"ERROR_INVALID_SERVICE_LOCK";
      case 0x430:
LAB_0072e92e:
        return L"ERROR_SERVICE_MARKED_FOR_DELETE";
      case 0x431:
LAB_0072e938:
        return L"ERROR_SERVICE_EXISTS";
      case 0x432:
LAB_0072e942:
        return L"ERROR_ALREADY_RUNNING_LKG";
      case 0x433:
LAB_0072e94c:
        return L"ERROR_SERVICE_DEPENDENCY_DELETED";
      case 0x434:
LAB_0072e956:
        return L"ERROR_BOOT_ALREADY_ACCEPTED";
      case 0x435:
LAB_0072e960:
        return L"ERROR_SERVICE_NEVER_STARTED";
      case 0x436:
LAB_0072e96a:
        return L"ERROR_DUPLICATE_SERVICE_NAME";
      case 0x437:
LAB_0072e974:
        return L"ERROR_DIFFERENT_SERVICE_ACCOUNT";
      case 0x438:
LAB_0072e97e:
        return L"ERROR_CANNOT_DETECT_DRIVER_FAILURE";
      case 0x439:
LAB_0072e988:
        return L"ERROR_CANNOT_DETECT_PROCESS_ABORT";
      case 0x43a:
LAB_0072e992:
        return L"ERROR_NO_RECOVERY_PROGRAM";
      case 0x43b:
LAB_0072e99c:
        return L"ERROR_SERVICE_NOT_IN_EXE";
      case 0x44c:
LAB_0072e9a6:
        return L"ERROR_END_OF_MEDIA";
      case 0x44d:
LAB_0072e9b0:
        return L"ERROR_FILEMARK_DETECTED";
      case 0x44e:
LAB_0072e9ba:
        return L"ERROR_BEGINNING_OF_MEDIA";
      case 0x44f:
LAB_0072e9c4:
        return L"ERROR_SETMARK_DETECTED";
      case 0x450:
LAB_0072e9ce:
        return L"ERROR_NO_DATA_DETECTED";
      case 0x451:
LAB_0072e9d8:
        return L"ERROR_PARTITION_FAILURE";
      case 0x452:
LAB_0072e9e2:
        return L"ERROR_INVALID_BLOCK_LENGTH";
      case 0x453:
LAB_0072e9ec:
        return L"ERROR_DEVICE_NOT_PARTITIONED";
      case 0x454:
LAB_0072e9f6:
        return L"ERROR_UNABLE_TO_LOCK_MEDIA";
      case 0x455:
LAB_0072ea00:
        return L"ERROR_UNABLE_TO_UNLOAD_MEDIA";
      case 0x456:
LAB_0072ea0a:
        return L"ERROR_MEDIA_CHANGED";
      case 0x457:
LAB_0072ea14:
        return L"ERROR_BUS_RESET";
      case 0x458:
LAB_0072ea1e:
        return L"ERROR_NO_MEDIA_IN_DRIVE";
      case 0x459:
LAB_0072ea28:
        return L"ERROR_NO_UNICODE_TRANSLATION";
      case 0x45a:
LAB_0072ea32:
        return L"ERROR_DLL_INIT_FAILED";
      case 0x45b:
LAB_0072ea3c:
        return L"ERROR_SHUTDOWN_IN_PROGRESS";
      case 0x45c:
LAB_0072ea46:
        return L"ERROR_NO_SHUTDOWN_IN_PROGRESS";
      case 0x45d:
LAB_0072ea50:
        return L"ERROR_IO_DEVICE";
      case 0x45e:
LAB_0072ea5a:
        return L"ERROR_SERIAL_NO_DEVICE";
      case 0x45f:
LAB_0072ea64:
        return L"ERROR_IRQ_BUSY";
      case 0x460:
LAB_0072ea6e:
        return L"ERROR_MORE_WRITES";
      case 0x461:
LAB_0072ea78:
        return L"ERROR_COUNTER_TIMEOUT";
      case 0x462:
LAB_0072ea82:
        return L"ERROR_FLOPPY_ID_MARK_NOT_FOUND";
      case 0x463:
LAB_0072ea8c:
        return L"ERROR_FLOPPY_WRONG_CYLINDER";
      case 0x464:
LAB_0072ea96:
        return L"ERROR_FLOPPY_UNKNOWN_ERROR";
      case 0x465:
LAB_0072eaa0:
        return L"ERROR_FLOPPY_BAD_REGISTERS";
      case 0x466:
LAB_0072eaaa:
        return L"ERROR_DISK_RECALIBRATE_FAILED";
      case 0x467:
LAB_0072eab4:
        return L"ERROR_DISK_OPERATION_FAILED";
      case 0x468:
LAB_0072eabe:
        return L"ERROR_DISK_RESET_FAILED";
      case 0x469:
LAB_0072eac8:
        return L"ERROR_EOM_OVERFLOW";
      case 0x46a:
LAB_0072ead2:
        return L"ERROR_NOT_ENOUGH_SERVER_MEMORY";
      case 0x46b:
LAB_0072eadc:
        return L"ERROR_POSSIBLE_DEADLOCK";
      case 0x46c:
LAB_0072eae6:
        return L"ERROR_MAPPED_ALIGNMENT";
      case 0x474:
LAB_0072eaf0:
        return L"ERROR_SET_POWER_STATE_VETOED";
      case 0x475:
LAB_0072eafa:
        return L"ERROR_SET_POWER_STATE_FAILED";
      case 0x476:
LAB_0072eb04:
        return L"ERROR_TOO_MANY_LINKS";
      case 0x47e:
LAB_0072eb0e:
        return L"ERROR_OLD_WIN_VERSION & DIERR_OLDDIRECTINPUTVERSION";
      case 0x47f:
LAB_0072eb18:
        return L"ERROR_APP_WRONG_OS";
      case 0x480:
LAB_0072eb22:
        return L"ERROR_SINGLE_INSTANCE_APP";
      case 0x481:
LAB_0072eb2c:
        return L"ERROR_RMODE_APP & DIERR_BETADIRECTINPUTVERSION";
      case 0x482:
LAB_0072eb36:
        return L"ERROR_INVALID_DLL";
      case 0x483:
        goto LAB_0072eb40;
      case 0x484:
        goto code_r0x0072eb4a;
      case 0x485:
        goto code_r0x0072eb54;
      case 0x486:
        goto code_r0x0072eb5e;
      case 0x487:
        goto code_r0x0072eb68;
      case 0x488:
        goto code_r0x0072eb72;
      case 0x489:
        goto code_r0x0072eb7c;
      case 0x48a:
        goto code_r0x0072eb86;
      case 0x48b:
        goto code_r0x0072eb90;
      case 0x48c:
        goto code_r0x0072eb9a;
      case 0x48d:
        goto code_r0x0072eba4;
      case 0x48e:
        goto code_r0x0072ebae;
      case 0x48f:
        goto code_r0x0072ebb8;
      case 0x490:
        goto code_r0x0072ebc2;
      case 0x491:
        goto code_r0x0072ebcc;
      case 0x492:
        goto code_r0x0072ebd6;
      case 0x493:
        goto code_r0x0072ebe0;
      case 0x494:
        goto code_r0x0072ebea;
      case 0x495:
        goto code_r0x0072ebf4;
      case 0x497:
        goto code_r0x0072ebfe;
      case 0x498:
        goto code_r0x0072ec08;
      case 0x499:
        goto code_r0x0072ec12;
      case 0x49a:
        goto code_r0x0072ec1c;
      case 0x49b:
        goto code_r0x0072ec26;
      case 0x49c:
        goto code_r0x0072ec30;
      case 0x49d:
        goto code_r0x0072f45a;
      case 0x4b0:
        goto code_r0x0072ec3a;
      case 0x4b1:
        goto code_r0x0072ec44;
      case 0x4b2:
        goto code_r0x0072ec4e;
      case 0x4b3:
        goto code_r0x0072ec58;
      case 0x4b4:
        goto code_r0x0072ec62;
      case 0x4b5:
        goto code_r0x0072ec6c;
      case 0x4b6:
        goto code_r0x0072ec76;
      case 0x4b7:
        goto code_r0x0072ec80;
      case 0x4b8:
        goto code_r0x0072ec8a;
      case 0x4b9:
        goto code_r0x0072ec94;
      case 0x4ba:
        goto code_r0x0072ec9e;
      case 0x4bb:
        goto code_r0x0072eca8;
      case 0x4bc:
        goto code_r0x0072ecb2;
      case 0x4bd:
        goto code_r0x0072ecbc;
      case 0x4be:
        goto code_r0x0072ecc6;
      case 0x4bf:
        goto code_r0x0072ecd0;
      case 0x4c0:
        goto code_r0x0072ecda;
      case 0x4c1:
        goto code_r0x0072ece4;
      case 0x4c2:
        goto code_r0x0072ecee;
      case 0x4c3:
        goto code_r0x0072ecf8;
      case 0x4c4:
        goto code_r0x0072ed02;
      case 0x4c5:
        goto code_r0x0072ed0c;
      case 0x4c6:
        goto code_r0x0072ed16;
      case 0x4c7:
        goto code_r0x0072ed20;
      case 0x4c8:
        goto code_r0x0072ed2a;
      case 0x4c9:
        goto code_r0x0072ed34;
      case 0x4ca:
        goto code_r0x0072ed3e;
      case 0x4cb:
        goto code_r0x0072ed48;
      case 0x4cc:
        goto code_r0x0072ed52;
      case 0x4cd:
        goto code_r0x0072ed5c;
      case 0x4ce:
        goto code_r0x0072ed66;
      case 0x4cf:
        goto code_r0x0072ed70;
      case 0x4d0:
        goto code_r0x0072ed7a;
      case 0x4d1:
        goto code_r0x0072ed84;
      case 0x4d2:
        goto code_r0x0072ed8e;
      case 0x4d3:
        goto code_r0x0072ed98;
      case 0x4d4:
        goto code_r0x0072eda2;
      case 0x4d5:
        goto code_r0x0072edac;
      case 0x4d6:
        goto code_r0x0072edb6;
      case 0x4d7:
        goto code_r0x0072edc0;
      case 0x4d8:
        goto code_r0x0072edca;
      case 0x4d9:
        goto code_r0x0072edd4;
      case 0x4da:
        goto code_r0x0072edde;
      case 0x4db:
        goto code_r0x0072ede8;
      case 0x4dc:
        goto code_r0x0072edf2;
      case 0x4dd:
        goto code_r0x0072edfc;
      case 0x4de:
        goto code_r0x0072ee06;
      case 0x4df:
        goto code_r0x0072ee10;
      case 0x4e0:
        goto code_r0x0072ee1a;
      case 0x4e1:
        goto code_r0x0072ee24;
      case 0x4e2:
        goto code_r0x0072ee2e;
      case 0x4e3:
        goto code_r0x0072f464;
      case 0x4e4:
        goto code_r0x0072f46e;
      case 0x4e5:
        goto code_r0x0072f478;
      case 0x4e6:
        goto code_r0x0072f482;
      case 0x4e7:
        goto code_r0x0072f48c;
      case 0x4e8:
        goto code_r0x0072f496;
      case 0x4e9:
        goto code_r0x0072f4a0;
      case 0x4ea:
        goto code_r0x0072f4aa;
      case 0x4eb:
        goto code_r0x0072f4b4;
      case 0x4ec:
        goto code_r0x0072f4be;
      case 0x4ed:
        goto code_r0x0072f4c8;
      case 0x4ee:
        goto code_r0x0072f4d2;
      case 0x4ef:
        goto code_r0x0072f4dc;
      case 0x4f0:
        goto LAB_0072f4e6;
      case 0x4f1:
        goto code_r0x0072f4f0;
      case 0x4f7:
        goto code_r0x0072f4fa;
      case 0x4f9:
        goto code_r0x0072f504;
      case 0x4fa:
        goto code_r0x0072f50e;
      case 0x4fb:
        goto code_r0x0072f518;
      case 0x4fc:
        goto code_r0x0072f522;
      case 0x514:
        goto code_r0x0072ee38;
      case 0x515:
        goto code_r0x0072ee42;
      case 0x516:
        goto code_r0x0072ee4c;
      case 0x517:
        goto code_r0x0072ee56;
      case 0x518:
        goto code_r0x0072ee60;
      case 0x519:
        goto code_r0x0072ee6a;
      case 0x51a:
        goto code_r0x0072ee74;
      case 0x51b:
        goto code_r0x0072ee7e;
      case 0x51c:
        goto code_r0x0072ee88;
      case 0x51d:
        goto code_r0x0072ee92;
      case 0x51e:
        goto code_r0x0072ee9c;
      case 0x51f:
        goto code_r0x0072eea6;
      case 0x520:
        goto code_r0x0072eeb0;
      case 0x521:
        goto code_r0x0072eeba;
      case 0x522:
        goto code_r0x0072eec4;
      case 0x523:
        goto code_r0x0072eece;
      case 0x524:
        goto code_r0x0072eed8;
      case 0x525:
        goto code_r0x0072eee2;
      case 0x526:
        goto code_r0x0072eeec;
      case 0x527:
        goto code_r0x0072eef6;
      case 0x528:
        goto code_r0x0072ef00;
      case 0x529:
        goto code_r0x0072ef0a;
      case 0x52a:
        goto code_r0x0072ef14;
      case 0x52b:
        goto code_r0x0072ef1e;
      case 0x52c:
        goto code_r0x0072ef28;
      case 0x52d:
        goto code_r0x0072ef32;
      case 0x52e:
        goto code_r0x0072ef3c;
      case 0x52f:
        goto code_r0x0072ef46;
      case 0x530:
        goto code_r0x0072ef50;
      case 0x531:
        goto code_r0x0072ef5a;
      case 0x532:
        goto code_r0x0072ef64;
      case 0x533:
        goto code_r0x0072ef6e;
      case 0x534:
        goto code_r0x0072ef78;
      case 0x535:
        goto code_r0x0072ef82;
      case 0x536:
        goto code_r0x0072ef8c;
      case 0x537:
        goto code_r0x0072ef96;
      case 0x538:
        goto code_r0x0072efa0;
      case 0x539:
        goto code_r0x0072efaa;
      case 0x53a:
        goto code_r0x0072efb4;
      case 0x53c:
        goto code_r0x0072efbe;
      case 0x53d:
        goto code_r0x0072efc8;
      case 0x53e:
        goto code_r0x0072efd2;
      case 0x53f:
        goto code_r0x0072efdc;
      case 0x540:
        goto code_r0x0072efe6;
      case 0x541:
        goto code_r0x0072eff0;
      case 0x542:
        goto code_r0x0072effa;
      case 0x543:
        goto code_r0x0072f004;
      case 0x544:
        goto code_r0x0072f00e;
      case 0x545:
        goto code_r0x0072f018;
      case 0x546:
        goto code_r0x0072f022;
      case 0x547:
        goto code_r0x0072f02c;
      case 0x548:
        goto code_r0x0072f036;
      case 0x549:
        goto code_r0x0072f040;
      case 0x54a:
        goto code_r0x0072f04a;
      case 0x54b:
        goto code_r0x0072f054;
      case 0x54c:
        goto code_r0x0072f05e;
      case 0x54d:
        goto code_r0x0072f068;
      case 0x54e:
        goto code_r0x0072f072;
      case 0x54f:
        goto code_r0x0072f07c;
      case 0x550:
        goto code_r0x0072f086;
      case 0x551:
        goto code_r0x0072f090;
      case 0x552:
        goto code_r0x0072f09a;
      case 0x553:
        goto code_r0x0072f0a4;
      case 0x554:
        goto code_r0x0072f0ae;
      case 0x555:
        goto code_r0x0072f0b8;
      case 0x556:
        goto code_r0x0072f0c2;
      case 0x557:
        goto code_r0x0072f0cc;
      case 0x558:
        goto code_r0x0072f0d6;
      case 0x559:
        goto code_r0x0072f0e0;
      case 0x55a:
        goto code_r0x0072f0ea;
      case 0x55b:
        goto code_r0x0072f0f4;
      case 0x55c:
        goto code_r0x0072f0fe;
      case 0x55d:
        goto code_r0x0072f108;
      case 0x55e:
        goto code_r0x0072f112;
      case 0x55f:
        goto code_r0x0072f11c;
      case 0x560:
        goto code_r0x0072f126;
      case 0x561:
        goto code_r0x0072f130;
      case 0x562:
        goto code_r0x0072f13a;
      case 0x563:
        goto code_r0x0072f144;
      case 0x564:
        goto code_r0x0072f14e;
      case 0x565:
        goto code_r0x0072f158;
      case 0x566:
        goto code_r0x0072f162;
      case 0x567:
        goto code_r0x0072f16c;
      case 0x568:
        goto code_r0x0072f176;
      case 0x569:
        goto code_r0x0072f180;
      case 0x56a:
        goto code_r0x0072f18a;
      case 0x56b:
        goto code_r0x0072f194;
      case 0x56c:
        goto code_r0x0072f19e;
      case 0x56d:
        goto code_r0x0072f1a8;
      case 0x56e:
        goto code_r0x0072f1b2;
      case 0x56f:
        goto code_r0x0072f1bc;
      case 0x570:
        goto code_r0x0072f1c6;
      case 0x571:
        goto code_r0x0072f1d0;
      case 0x572:
        goto code_r0x0072f1da;
      case 0x573:
        goto code_r0x0072f1e4;
      case 0x574:
        goto code_r0x0072f1ee;
      case 0x575:
        goto code_r0x0072f1f8;
      case 0x576:
        goto code_r0x0072f202;
      case 0x577:
        goto code_r0x0072f52c;
      case 0x578:
        goto code_r0x0072f20c;
      case 0x579:
        goto code_r0x0072f216;
      case 0x57a:
        goto code_r0x0072f220;
      case 0x57b:
        goto code_r0x0072f22a;
      case 0x57c:
        goto code_r0x0072f234;
      case 0x57d:
        goto code_r0x0072f23e;
      case 0x57e:
        goto code_r0x0072f248;
      case 0x57f:
        goto code_r0x0072f252;
      case 0x580:
        goto code_r0x0072f25c;
      case 0x581:
        goto code_r0x0072f266;
      case 0x582:
        goto code_r0x0072f270;
      case 0x583:
        goto code_r0x0072f27a;
      case 0x584:
        goto code_r0x0072f284;
      case 0x585:
        goto code_r0x0072f28e;
      case 0x586:
        goto code_r0x0072f298;
      case 0x587:
        goto code_r0x0072f2a2;
      case 0x588:
        goto code_r0x0072f2ac;
      case 0x589:
        goto code_r0x0072f2b6;
      case 0x58a:
        goto code_r0x0072f2c0;
      case 0x58b:
        goto code_r0x0072f2ca;
      case 0x58c:
        goto code_r0x0072f2d4;
      case 0x58d:
        goto code_r0x0072f2de;
      case 0x58e:
        goto code_r0x0072f2e8;
      case 0x58f:
        goto code_r0x0072f2f2;
      case 0x590:
        goto code_r0x0072f2fc;
      case 0x591:
        goto code_r0x0072f306;
      case 0x592:
        goto code_r0x0072f310;
      case 0x593:
        goto code_r0x0072f31a;
      case 0x594:
        goto code_r0x0072f324;
      case 0x595:
        goto code_r0x0072f32e;
      case 0x596:
        goto code_r0x0072f338;
      case 0x597:
        goto code_r0x0072f342;
      case 0x598:
        goto code_r0x0072f34c;
      case 0x599:
        goto code_r0x0072f356;
      case 0x59a:
        goto code_r0x0072f360;
      case 0x59b:
        goto code_r0x0072f36a;
      case 0x59c:
        goto code_r0x0072f374;
      case 0x59d:
        goto code_r0x0072f37e;
      case 0x59e:
        goto code_r0x0072f388;
      case 0x59f:
        goto code_r0x0072f392;
      case 0x5a0:
        goto code_r0x0072f39c;
      case 0x5a1:
        goto code_r0x0072f3a6;
      case 0x5a2:
        goto code_r0x0072f3b0;
      case 0x5a3:
        goto code_r0x0072f3ba;
      case 0x5a4:
        goto code_r0x0072f3c4;
      case 0x5a5:
        goto code_r0x0072f3ce;
      case 0x5a6:
        goto code_r0x0072f3d8;
      case 0x5a7:
        goto code_r0x0072f3e2;
      case 0x5a8:
        goto code_r0x0072f3ec;
      case 0x5a9:
        goto code_r0x0072f3f6;
      case 0x5aa:
        goto code_r0x0072f400;
      case 0x5ab:
        goto code_r0x0072f40a;
      case 0x5ac:
        goto code_r0x0072f414;
      case 0x5ad:
        goto code_r0x0072f41e;
      case 0x5ae:
        goto code_r0x0072f428;
      case 0x5af:
        goto code_r0x0072f432;
      case 0x5b0:
        goto code_r0x0072f43c;
      case 0x5b1:
        goto code_r0x0072f446;
      case 0x5b2:
        goto code_r0x0072f450;
      }
    }
  }
  else if (param_1 < 0x20e1) {
    if (param_1 == 0x20e0) {
LAB_00731361:
      return L"ERROR_DS_ATT_SCHEMA_REQ_SYNTAX";
    }
    if (param_1 < 0x1395) {
      if (param_1 == 0x1394) {
LAB_007304a3:
        return L"ERROR_GROUP_NOT_AVAILABLE";
      }
      if (param_1 < 0x720) {
        if (param_1 == 0x71f) goto LAB_0072fc31;
        if (param_1 - 0x5b4U < 0x16b) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(*(undefined1 *)((int)&PTR_LAB_007378b2 + param_1)) {
          case 0:
            goto code_r0x0072f597;
          case 1:
            goto code_r0x0072f5a1;
          case 2:
            goto code_r0x0072f5ab;
          case 3:
            goto code_r0x0072f5b5;
          case 4:
            goto code_r0x0072f5bf;
          case 5:
            goto code_r0x0072f5c9;
          case 6:
            goto code_r0x0072fb0f;
          case 7:
            goto code_r0x0072f5d3;
          case 8:
            goto code_r0x0072f5dd;
          case 9:
            goto code_r0x0072f5e7;
          case 10:
            goto code_r0x0072f5f1;
          case 0xb:
            goto code_r0x0072f5fb;
          case 0xc:
            goto code_r0x0072f605;
          case 0xd:
            goto code_r0x0072f60f;
          case 0xe:
            goto code_r0x0072f619;
          case 0xf:
            goto code_r0x0072f623;
          case 0x10:
            goto code_r0x0072f62d;
          case 0x11:
            goto code_r0x0072f637;
          case 0x12:
            goto code_r0x0072fb19;
          case 0x13:
            goto code_r0x0072f641;
          case 0x14:
            goto code_r0x0072f64b;
          case 0x15:
            goto code_r0x0072f655;
          case 0x16:
            goto code_r0x0072f65f;
          case 0x17:
            goto code_r0x0072fb23;
          case 0x18:
            goto code_r0x0072fb2d;
          case 0x19:
            goto code_r0x0072fb37;
          case 0x1a:
            goto code_r0x0072fb41;
          case 0x1b:
            goto code_r0x0072fb4b;
          case 0x1c:
            goto code_r0x0072fb55;
          case 0x1d:
            goto code_r0x0072fb5f;
          case 0x1e:
            goto code_r0x0072fb69;
          case 0x1f:
            goto code_r0x0072fb73;
          case 0x20:
            goto code_r0x0072fb7d;
          case 0x21:
            goto code_r0x0072fb87;
          case 0x22:
            goto code_r0x0072fb91;
          case 0x23:
            goto code_r0x0072fb9b;
          case 0x24:
            goto code_r0x0072fba5;
          case 0x25:
            goto code_r0x0072fbaf;
          case 0x26:
            goto code_r0x0072fbb9;
          case 0x27:
            goto code_r0x0072fbc3;
          case 0x28:
            goto code_r0x0072fbcd;
          case 0x29:
            goto code_r0x0072fbd7;
          case 0x2a:
            goto code_r0x0072fbe1;
          case 0x2b:
            goto code_r0x0072fbeb;
          case 0x2c:
            goto code_r0x0072fbf5;
          case 0x2d:
            goto code_r0x0072fbff;
          case 0x2e:
            goto code_r0x0072fc09;
          case 0x2f:
            goto code_r0x0072fc13;
          case 0x30:
            goto code_r0x0072fc1d;
          case 0x31:
            goto code_r0x0072fc27;
          case 0x32:
            goto code_r0x0072f669;
          case 0x33:
            goto code_r0x0072f673;
          case 0x34:
            goto code_r0x0072f67d;
          case 0x35:
            goto code_r0x0072f687;
          case 0x36:
            goto code_r0x0072f691;
          case 0x37:
            goto code_r0x0072f69b;
          case 0x38:
            goto code_r0x0072f6a5;
          case 0x39:
            goto code_r0x0072f6af;
          case 0x3a:
            goto code_r0x0072f6b9;
          case 0x3b:
            goto code_r0x0072f6c3;
          case 0x3c:
            goto code_r0x0072f6cd;
          case 0x3d:
            goto code_r0x0072f6d7;
          case 0x3e:
            goto code_r0x0072f6e1;
          case 0x3f:
            goto code_r0x0072f6eb;
          case 0x40:
            goto code_r0x0072f6f5;
          case 0x41:
            goto code_r0x0072f6ff;
          case 0x42:
            goto code_r0x0072f709;
          case 0x43:
            goto code_r0x0072f713;
          case 0x44:
            goto LAB_0072f71d;
          case 0x45:
            goto code_r0x0072f727;
          case 0x46:
            goto code_r0x0072f731;
          case 0x47:
            goto code_r0x0072f73b;
          case 0x48:
            goto code_r0x0072f745;
          case 0x49:
            goto code_r0x0072f74f;
          case 0x4a:
            goto code_r0x0072f759;
          case 0x4b:
            goto code_r0x0072f763;
          case 0x4c:
            goto code_r0x0072f76d;
          case 0x4d:
            goto code_r0x0072f777;
          case 0x4e:
            goto code_r0x0072f781;
          case 0x4f:
            goto code_r0x0072f78b;
          case 0x50:
            goto code_r0x0072f795;
          case 0x51:
            goto code_r0x0072f79f;
          case 0x52:
            goto code_r0x0072f7a9;
          case 0x53:
            goto code_r0x0072f7b3;
          case 0x54:
            goto code_r0x0072f7bd;
          case 0x55:
            goto code_r0x0072f7c7;
          case 0x56:
            goto code_r0x0072f7d1;
          case 0x57:
            goto code_r0x0072f7db;
          case 0x58:
            goto code_r0x0072f7e5;
          case 0x59:
            goto code_r0x0072f7ef;
          case 0x5a:
            goto code_r0x0072f7f9;
          case 0x5b:
            goto code_r0x0072f803;
          case 0x5c:
            goto code_r0x0072f80d;
          case 0x5d:
            goto code_r0x0072f817;
          case 0x5e:
            goto code_r0x0072f821;
          case 0x5f:
            goto code_r0x0072f82b;
          case 0x60:
            goto code_r0x0072f835;
          case 0x61:
            goto code_r0x0072f83f;
          case 0x62:
            goto code_r0x0072f849;
          case 99:
            goto code_r0x0072f853;
          case 100:
            goto code_r0x0072f85d;
          case 0x65:
            goto code_r0x0072f867;
          case 0x66:
            goto code_r0x0072f871;
          case 0x67:
            goto code_r0x0072f87b;
          case 0x68:
            goto code_r0x0072f885;
          case 0x69:
            goto code_r0x0072f88f;
          case 0x6a:
            goto code_r0x0072f899;
          case 0x6b:
            goto code_r0x0072f8a3;
          case 0x6c:
            goto code_r0x0072f8ad;
          case 0x6d:
            goto code_r0x0072f8b7;
          case 0x6e:
            goto code_r0x0072f8c1;
          case 0x6f:
            goto code_r0x0072f8cb;
          case 0x70:
            goto code_r0x0072f8d5;
          case 0x71:
            goto code_r0x0072f8df;
          case 0x72:
            goto code_r0x0072f8e9;
          case 0x73:
            goto code_r0x0072f8f3;
          case 0x74:
            goto code_r0x0072f8fd;
          case 0x75:
            goto code_r0x0072f907;
          case 0x76:
            goto code_r0x0072f911;
          case 0x77:
            goto code_r0x0072f91b;
          case 0x78:
            goto code_r0x0072f925;
          case 0x79:
            goto code_r0x0072f92f;
          case 0x7a:
            goto code_r0x0072f939;
          case 0x7b:
            goto code_r0x0072f943;
          case 0x7c:
            goto code_r0x0072f94d;
          case 0x7d:
            goto code_r0x0072f957;
          case 0x7e:
            goto code_r0x0072f961;
          case 0x7f:
            goto code_r0x0072f96b;
          case 0x80:
            goto code_r0x0072f975;
          case 0x81:
            goto code_r0x0072f97f;
          case 0x82:
            goto code_r0x0072f989;
          case 0x83:
            goto code_r0x0072f993;
          case 0x84:
            goto code_r0x0072f99d;
          case 0x85:
            goto code_r0x0072f9a7;
          case 0x86:
            goto code_r0x0072f9b1;
          case 0x87:
            goto code_r0x0072f9bb;
          case 0x88:
            goto code_r0x0072f9c5;
          case 0x89:
            goto code_r0x0072f9cf;
          case 0x8a:
            goto code_r0x0072f9d9;
          case 0x8b:
            goto code_r0x0072f9e3;
          case 0x8c:
            goto code_r0x0072f9ed;
          case 0x8d:
            goto code_r0x0072f9f7;
          case 0x8e:
            goto code_r0x0072fa01;
          case 0x8f:
            goto code_r0x0072fa0b;
          case 0x90:
            goto code_r0x0072fa15;
          case 0x91:
            goto code_r0x0072fa1f;
          case 0x92:
            goto code_r0x0072fa29;
          case 0x93:
            goto code_r0x0072fa33;
          case 0x94:
            goto code_r0x0072fa3d;
          case 0x95:
            goto code_r0x0072fa47;
          case 0x96:
            goto code_r0x0072fa51;
          case 0x97:
            goto code_r0x0072fa5b;
          case 0x98:
            goto code_r0x0072fa65;
          case 0x99:
            goto code_r0x0072fa6f;
          case 0x9a:
            goto code_r0x0072fa79;
          case 0x9b:
            goto code_r0x0072fa83;
          case 0x9c:
            goto code_r0x0072fa8d;
          case 0x9d:
            goto code_r0x0072fa97;
          case 0x9e:
            goto code_r0x0072faa1;
          case 0x9f:
            goto code_r0x0072faab;
          case 0xa0:
            goto code_r0x0072fab5;
          case 0xa1:
            goto code_r0x0072fabf;
          case 0xa2:
            goto code_r0x0072fac9;
          case 0xa3:
            goto code_r0x0072fad3;
          case 0xa4:
            goto code_r0x0072fadd;
          case 0xa5:
            goto code_r0x0072fae7;
          case 0xa6:
            goto code_r0x0072faf1;
          case 0xa7:
            goto code_r0x0072fafb;
          case 0xa8:
            goto code_r0x0072fb05;
          }
        }
      }
      else if (param_1 < 0x76b) {
        if (param_1 == 0x76a) goto LAB_0072fcb5;
        switch(param_1) {
        case 0x720:
          goto code_r0x0072fc5b;
        case 0x721:
          goto code_r0x0072fc65;
        case 0x722:
          goto code_r0x0072fc6f;
        case 0x723:
          goto code_r0x0072fc79;
        case 0x724:
          goto code_r0x0072fc83;
        case 0x725:
          goto code_r0x0072fc8d;
        case 0x726:
          goto code_r0x0072fc97;
        case 0x727:
          goto code_r0x0072fca1;
        case 0x728:
          goto code_r0x0072fcab;
        }
      }
      else if (param_1 < 0x7d1) {
        if (param_1 == 2000) goto LAB_0072fe31;
        switch(param_1) {
        case 0x76b:
          goto code_r0x0072fce7;
        case 0x76c:
          goto code_r0x0072fcf1;
        case 0x76d:
          goto code_r0x0072fcfb;
        case 0x76e:
          goto code_r0x0072fd05;
        case 0x76f:
          goto code_r0x0072fd0f;
        case 0x770:
          goto code_r0x0072fd19;
        case 0x771:
          goto code_r0x0072fd23;
        case 0x772:
          goto code_r0x0072fd2d;
        case 0x773:
          goto code_r0x0072fd37;
        case 0x774:
          goto code_r0x0072fd41;
        case 0x775:
          goto code_r0x0072fd4b;
        case 0x776:
          goto code_r0x0072fd55;
        case 0x777:
          goto code_r0x0072fd5f;
        case 0x778:
          goto code_r0x0072fd69;
        case 0x779:
          goto code_r0x0072fd73;
        case 0x77a:
          goto code_r0x0072fd7d;
        case 0x77b:
          goto code_r0x0072fd87;
        case 0x77c:
          goto code_r0x0072fd91;
        case 0x77d:
          goto code_r0x0072fd9b;
        case 0x77e:
          goto code_r0x0072fda5;
        case 0x77f:
          goto code_r0x0072fdaf;
        case 0x780:
          goto code_r0x0072fdb9;
        case 0x781:
          goto code_r0x0072fdc3;
        case 0x782:
          goto code_r0x0072fdcd;
        case 0x783:
          goto code_r0x0072fdd7;
        case 0x784:
          goto code_r0x0072fde1;
        case 0x785:
          goto code_r0x0072fdeb;
        case 0x786:
          goto code_r0x0072fdf5;
        case 0x787:
          goto code_r0x0072fdff;
        case 0x788:
          goto code_r0x0072fe09;
        case 0x789:
          goto code_r0x0072fe13;
        case 0x78a:
          goto code_r0x0072fe1d;
        case 0x78b:
          goto code_r0x0072fe27;
        }
      }
      else if (param_1 < 0x83d) {
        if (param_1 == 0x83c) goto LAB_0072ff17;
        switch(param_1) {
        case 0x7d1:
          goto code_r0x0072fe63;
        case 0x7d2:
          goto code_r0x0072fe6d;
        case 0x7d3:
          goto code_r0x0072fe77;
        case 0x7d4:
          goto code_r0x0072fe81;
        case 0x7d5:
          goto code_r0x0072fe8b;
        case 0x7da:
          goto code_r0x0072fe95;
        case 0x7db:
          goto code_r0x0072fe9f;
        case 0x7dc:
          goto code_r0x0072fea9;
        case 0x7dd:
          goto code_r0x0072feb3;
        case 0x7de:
          goto code_r0x0072febd;
        case 0x7df:
          goto code_r0x0072fec7;
        case 0x7e0:
          goto code_r0x0072fed1;
        case 0x7e1:
          goto code_r0x0072fedb;
        case 0x7e2:
          goto code_r0x0072fee5;
        case 0x7e3:
          goto code_r0x0072feef;
        case 0x7e4:
          goto code_r0x0072fef9;
        case 0x7e5:
          goto code_r0x0072ff03;
        case 0x7e6:
          goto code_r0x0072ff0d;
        }
      }
      else if (param_1 < 0x10d5) {
        if (param_1 == 0x10d4) goto LAB_00730261;
        if (param_1 < 0xfa6) {
          if (param_1 == 0xfa5) {
LAB_007300d4:
            return L"ERROR_REC_NON_EXISTENT";
          }
          if (param_1 < 0xbc0) {
            if (param_1 == 0xbbf) goto LAB_00730016;
            if (param_1 < 0xbb9) {
              if (param_1 == 3000) {
LAB_00729e7d:
                return L"ERROR_UNKNOWN_PRINT_MONITOR";
              }
              if (param_1 == 0x83d) goto LAB_0072ffbc;
              if (param_1 == 0x89a) goto LAB_0072ffb2;
              if (param_1 == 0x8ca) goto LAB_0072ffa8;
              if (param_1 == 0x961) goto LAB_0072ff9e;
              if (param_1 == 0x962) goto LAB_0072ff94;
              if (param_1 == 0x964) goto LAB_0072ff8a;
            }
            else {
              if (param_1 == 0xbb9) goto LAB_0073000c;
              if (param_1 == 0xbba) goto LAB_00730002;
              if (param_1 == 0xbbb) goto LAB_0072fff8;
              if (param_1 == 0xbbc) goto LAB_0072ffee;
              if (param_1 == 0xbbd) goto LAB_00729eb3;
              if (param_1 == 0xbbe) goto LAB_0072ffe4;
            }
          }
          else if (param_1 < 0xbc7) {
            if (param_1 == 0xbc6) goto LAB_00730081;
            if (param_1 == 0xbc0) goto LAB_00730077;
            if (param_1 == 0xbc1) goto LAB_0073006d;
            if (param_1 == 0xbc2) goto LAB_00730063;
            if (param_1 == 0xbc3) goto LAB_00730059;
            if (param_1 == 0xbc4) goto LAB_0073004f;
            if (param_1 == 0xbc5) goto code_r0x00730045;
          }
          else {
            if (param_1 == 4000) goto LAB_007300ca;
            if (param_1 == 0xfa1) goto LAB_007300c0;
            if (param_1 == 0xfa2) goto LAB_007300b6;
            if (param_1 == 0xfa3) goto LAB_007300ac;
            if (param_1 == 0xfa4) goto LAB_007300a2;
          }
        }
        else if (param_1 < 0x1073) {
          if (param_1 == 0x1072) goto LAB_007301a1;
          if (param_1 < 0x106d) {
            if (param_1 == 0x106c) goto LAB_0073014e;
            if (param_1 == 0xfa6) goto LAB_00730144;
            if (param_1 == 0x1004) goto LAB_0073013a;
            if (param_1 == 0x1068) goto LAB_00730130;
            if (param_1 == 0x1069) goto LAB_00729f4d;
            if (param_1 == 0x106a) goto LAB_00730126;
            if (param_1 == 0x106b) goto code_r0x0073011c;
          }
          else {
            if (param_1 == 0x106d) goto LAB_00730197;
            if (param_1 == 0x106e) goto LAB_0073018d;
            if (param_1 == 0x106f) goto LAB_00730183;
            if (param_1 == 0x1070) goto LAB_00730179;
            if (param_1 == 0x1071) goto code_r0x0073016f;
          }
        }
        else if (param_1 < 0x10cf) {
          if (param_1 == 0x10ce) goto LAB_0073020e;
          if (param_1 == 0x1073) goto LAB_00730204;
          if (param_1 == 0x1074) goto LAB_007301fa;
          if (param_1 == 0x1075) goto LAB_007301f0;
          if (param_1 == 0x1076) goto LAB_007301e6;
          if (param_1 == 0x10cc) goto LAB_007301dc;
          if (param_1 == 0x10cd) goto code_r0x007301d2;
        }
        else {
          if (param_1 == 0x10cf) goto LAB_00730257;
          if (param_1 == 0x10d0) goto LAB_0073024d;
          if (param_1 == 0x10d1) goto LAB_00730243;
          if (param_1 == 0x10d2) goto LAB_00730239;
          if (param_1 == 0x10d3) goto code_r0x0073022f;
        }
      }
      else if (param_1 < 0x1195) {
        if (param_1 == 0x1194) {
LAB_0073042a:
          return L"ERROR_VOLUME_NOT_SIS_ENABLED";
        }
        switch(param_1) {
        case 0x10d5:
          goto code_r0x0073029a;
        case 0x10d6:
          goto code_r0x007302a4;
        case 0x10d7:
          goto code_r0x007302ae;
        case 0x10d8:
          goto code_r0x007302b8;
        case 0x10d9:
          goto code_r0x007302c2;
        case 0x10da:
          goto code_r0x007302cc;
        case 0x10db:
          goto code_r0x007302d6;
        case 0x10dc:
          goto code_r0x007302e0;
        case 0x10dd:
          goto code_r0x007302ea;
        case 0x10de:
          goto code_r0x007302f4;
        case 0x10df:
          goto code_r0x007302fe;
        case 0x10e0:
          goto code_r0x00730308;
        case 0x10e1:
          goto code_r0x00730312;
        case 0x10e2:
          goto code_r0x0073031c;
        case 0x10e3:
          goto code_r0x00730326;
        case 0x10e4:
          goto code_r0x00730330;
        case 0x10e5:
          goto code_r0x0073033a;
        case 0x10e6:
          goto code_r0x00730344;
        case 0x10e7:
          goto code_r0x0073034e;
        case 0x10e8:
          goto code_r0x00730358;
        case 0x10e9:
          goto code_r0x00730362;
        case 0x10ea:
          goto code_r0x0073036c;
        case 0x10eb:
          goto code_r0x00730376;
        case 0x10ec:
          goto code_r0x00730380;
        case 0x10ed:
          goto LAB_0073038a;
        case 0x10ee:
          goto code_r0x00730394;
        case 0x10ef:
          goto code_r0x0073039e;
        case 0x10f0:
          goto code_r0x007303a8;
        case 0x10f1:
          goto code_r0x007303ee;
        case 0x10f2:
          goto code_r0x007303f8;
        case 0x10f3:
          goto code_r0x00730402;
        case 0x10f4:
          goto code_r0x0073040c;
        case 0x10fe:
          goto code_r0x007303b2;
        case 0x10ff:
          goto code_r0x007303bc;
        case 0x1100:
          goto code_r0x007303c6;
        case 0x1126:
          goto LAB_007303d0;
        case 0x1127:
LAB_007303da:
          return L"ERROR_REPARSE_ATTRIBUTE_CONFLICT";
        case 0x1128:
LAB_007303e4:
          return L"ERROR_INVALID_REPARSE_DATA";
        case 0x1129:
LAB_00730416:
          return L"ERROR_REPARSE_TAG_INVALID";
        case 0x112a:
LAB_00730420:
          return L"ERROR_REPARSE_TAG_MISMATCH";
        }
      }
      else {
        switch(param_1) {
        case 0x1389:
LAB_00730449:
          return L"ERROR_DEPENDENT_RESOURCE_EXISTS";
        case 0x138a:
code_r0x0072a033:
          return L"ERROR_DEPENDENCY_NOT_FOUND";
        case 0x138b:
LAB_00730453:
          return L"ERROR_DEPENDENCY_ALREADY_EXISTS";
        case 0x138c:
LAB_0073045d:
          return L"ERROR_RESOURCE_NOT_ONLINE";
        case 0x138d:
LAB_00730467:
          return L"ERROR_HOST_NODE_NOT_AVAILABLE";
        case 0x138e:
LAB_00730471:
          return L"ERROR_RESOURCE_NOT_AVAILABLE";
        case 0x138f:
LAB_0073047b:
          return L"ERROR_RESOURCE_NOT_FOUND";
        case 0x1390:
LAB_00730485:
          return L"ERROR_SHUTDOWN_CLUSTER";
        case 0x1391:
LAB_0073048f:
          return L"ERROR_CANT_EVICT_ACTIVE_NODE";
        case 0x1392:
code_r0x0072a08a:
          return L"ERROR_OBJECT_ALREADY_EXISTS";
        case 0x1393:
LAB_00730499:
          return L"ERROR_OBJECT_IN_LIST";
        }
      }
    }
    else if (param_1 < 0x1703) {
      if (param_1 == 0x1702) {
LAB_007307cd:
        return L"ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE";
      }
      switch(param_1) {
      case 0x1395:
code_r0x007304d5:
        return L"ERROR_GROUP_NOT_FOUND";
      case 0x1396:
code_r0x007304df:
        return L"ERROR_GROUP_NOT_ONLINE";
      case 0x1397:
code_r0x007304e9:
        return L"ERROR_HOST_NODE_NOT_RESOURCE_OWNER";
      case 0x1398:
code_r0x007304f3:
        return L"ERROR_HOST_NODE_NOT_GROUP_OWNER";
      case 0x1399:
code_r0x007304fd:
        return L"ERROR_RESMON_CREATE_FAILED";
      case 0x139a:
code_r0x00730507:
        return L"ERROR_RESMON_ONLINE_FAILED";
      case 0x139b:
code_r0x00730511:
        return L"ERROR_RESOURCE_ONLINE";
      case 0x139c:
code_r0x0073051b:
        return L"ERROR_QUORUM_RESOURCE";
      case 0x139d:
code_r0x00730525:
        return L"ERROR_NOT_QUORUM_CAPABLE";
      case 0x139e:
code_r0x0073052f:
        return L"ERROR_CLUSTER_SHUTTING_DOWN";
      case 0x139f:
code_r0x00730539:
        return L"ERROR_INVALID_STATE";
      case 0x13a0:
code_r0x00730543:
        return L"ERROR_RESOURCE_PROPERTIES_STORED";
      case 0x13a1:
code_r0x0073054d:
        return L"ERROR_NOT_QUORUM_CLASS";
      case 0x13a2:
code_r0x00730557:
        return L"ERROR_CORE_RESOURCE";
      case 0x13a3:
LAB_00730561:
        return L"ERROR_QUORUM_RESOURCE_ONLINE_FAILED";
      case 0x13a4:
code_r0x0073056b:
        return L"ERROR_QUORUMLOG_OPEN_FAILED";
      case 0x13a5:
code_r0x00730575:
        return L"ERROR_CLUSTERLOG_CORRUPT";
      case 0x13a6:
code_r0x0073057f:
        return L"ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE";
      case 0x13a7:
code_r0x00730589:
        return L"ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE";
      case 0x13a8:
code_r0x00730593:
        return L"ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND";
      case 0x13a9:
code_r0x0073059d:
        return L"ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE";
      case 0x13aa:
code_r0x007305a7:
        return L"ERROR_QUORUM_OWNER_ALIVE";
      case 0x13ab:
code_r0x007305b1:
        return L"ERROR_NETWORK_NOT_AVAILABLE";
      case 0x13ac:
code_r0x007305bb:
        return L"ERROR_NODE_NOT_AVAILABLE";
      case 0x13ad:
code_r0x007305c5:
        return L"ERROR_ALL_NODES_NOT_AVAILABLE";
      case 0x13ae:
code_r0x007305cf:
        return L"ERROR_RESOURCE_FAILED";
      case 0x13af:
code_r0x007305d9:
        return L"ERROR_CLUSTER_INVALID_NODE";
      case 0x13b0:
code_r0x007305e3:
        return L"ERROR_CLUSTER_NODE_EXISTS";
      case 0x13b1:
code_r0x007305ed:
        return L"ERROR_CLUSTER_JOIN_IN_PROGRESS";
      case 0x13b2:
code_r0x007305f7:
        return L"ERROR_CLUSTER_NODE_NOT_FOUND";
      case 0x13b3:
code_r0x00730601:
        return L"ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND";
      case 0x13b4:
code_r0x0073060b:
        return L"ERROR_CLUSTER_NETWORK_EXISTS";
      case 0x13b5:
code_r0x00730615:
        return L"ERROR_CLUSTER_NETWORK_NOT_FOUND";
      case 0x13b6:
code_r0x0073061f:
        return L"ERROR_CLUSTER_NETINTERFACE_EXISTS";
      case 0x13b7:
code_r0x00730629:
        return L"ERROR_CLUSTER_NETINTERFACE_NOT_FOUND";
      case 0x13b8:
code_r0x00730633:
        return L"ERROR_CLUSTER_INVALID_REQUEST";
      case 0x13b9:
code_r0x0073063d:
        return L"ERROR_CLUSTER_INVALID_NETWORK_PROVIDER";
      case 0x13ba:
code_r0x00730647:
        return L"ERROR_CLUSTER_NODE_DOWN";
      case 0x13bb:
code_r0x00730651:
        return L"ERROR_CLUSTER_NODE_UNREACHABLE";
      case 0x13bc:
code_r0x0073065b:
        return L"ERROR_CLUSTER_NODE_NOT_MEMBER";
      case 0x13bd:
code_r0x00730665:
        return L"ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS";
      case 0x13be:
code_r0x0073066f:
        return L"ERROR_CLUSTER_INVALID_NETWORK";
      case 0x13c0:
code_r0x00730679:
        return L"ERROR_CLUSTER_NODE_UP";
      case 0x13c1:
code_r0x00730683:
        return L"ERROR_CLUSTER_IPADDR_IN_USE";
      case 0x13c2:
code_r0x0073068d:
        return L"ERROR_CLUSTER_NODE_NOT_PAUSED";
      case 0x13c3:
code_r0x00730697:
        return L"ERROR_CLUSTER_NO_SECURITY_CONTEXT";
      case 0x13c4:
        goto LAB_007306a1;
      case 0x13c5:
code_r0x007306ab:
        return L"ERROR_CLUSTER_NODE_ALREADY_UP";
      case 0x13c6:
code_r0x007306b5:
        return L"ERROR_CLUSTER_NODE_ALREADY_DOWN";
      case 0x13c7:
code_r0x007306bf:
        return L"ERROR_CLUSTER_NETWORK_ALREADY_ONLINE";
      case 0x13c8:
code_r0x007306c9:
        return L"ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE";
      case 0x13c9:
code_r0x007306d3:
        return L"ERROR_CLUSTER_NODE_ALREADY_MEMBER";
      case 0x13ca:
code_r0x007306dd:
        return L"ERROR_CLUSTER_LAST_INTERNAL_NETWORK";
      case 0x13cb:
code_r0x007306e7:
        return L"ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS";
      case 0x13cc:
code_r0x007306f1:
        return L"ERROR_INVALID_OPERATION_ON_QUORUM";
      case 0x13cd:
code_r0x007306fb:
        return L"ERROR_DEPENDENCY_NOT_ALLOWED";
      case 0x13ce:
code_r0x00730705:
        return L"ERROR_CLUSTER_NODE_PAUSED";
      case 0x13cf:
code_r0x0073070f:
        return L"ERROR_NODE_CANT_HOST_RESOURCE";
      case 0x13d0:
code_r0x00730719:
        return L"ERROR_CLUSTER_NODE_NOT_READY";
      case 0x13d1:
code_r0x00730723:
        return L"ERROR_CLUSTER_NODE_SHUTTING_DOWN";
      case 0x13d2:
code_r0x0073072d:
        return L"ERROR_CLUSTER_JOIN_ABORTED";
      case 0x13d3:
code_r0x00730737:
        return L"ERROR_CLUSTER_INCOMPATIBLE_VERSIONS";
      case 0x13d4:
code_r0x00730741:
        return L"ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED";
      case 0x13d5:
code_r0x0073074b:
        return L"ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED";
      case 0x13d6:
code_r0x00730755:
        return L"ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND";
      case 0x13d7:
code_r0x0073075f:
        return L"ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED";
      case 0x13d8:
code_r0x00730769:
        return L"ERROR_CLUSTER_RESNAME_NOT_FOUND";
      case 0x13d9:
code_r0x00730773:
        return L"ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED";
      case 0x13da:
code_r0x0073077d:
        return L"ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST";
      case 0x13db:
code_r0x00730787:
        return L"ERROR_CLUSTER_DATABASE_SEQMISMATCH";
      case 0x13dc:
code_r0x00730791:
        return L"ERROR_RESMON_INVALID_STATE";
      case 0x13dd:
code_r0x0073079b:
        return L"ERROR_CLUSTER_GUM_NOT_LOCKER";
      case 0x13de:
code_r0x007307a5:
        return L"ERROR_QUORUM_DISK_NOT_FOUND";
      case 0x13df:
code_r0x007307af:
        return L"ERROR_DATABASE_BACKUP_CORRUPT";
      case 0x13e0:
code_r0x007307b9:
        return L"ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT";
      case 0x13e1:
code_r0x007307c3:
        return L"ERROR_RESOURCE_PROPERTY_UNCHANGEABLE";
      }
    }
    else if (param_1 < 0x1771) {
      if (param_1 == 6000) {
LAB_0073085f:
        return L"ERROR_ENCRYPTION_FAILED";
      }
      switch(param_1) {
      case 0x1703:
code_r0x007307fb:
        return L"ERROR_CLUSTER_QUORUMLOG_NOT_FOUND";
      case 0x1704:
code_r0x00730805:
        return L"ERROR_CLUSTER_MEMBERSHIP_HALT";
      case 0x1705:
code_r0x0073080f:
        return L"ERROR_CLUSTER_INSTANCE_ID_MISMATCH";
      case 0x1706:
code_r0x00730819:
        return L"ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP";
      case 0x1707:
code_r0x00730823:
        return L"ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH";
      case 0x1708:
code_r0x0073082d:
        return L"ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP";
      case 0x1709:
code_r0x00730837:
        return L"ERROR_CLUSTER_PARAMETER_MISMATCH";
      case 0x170a:
code_r0x00730841:
        return L"ERROR_NODE_CANNOT_BE_CLUSTERED";
      case 0x170b:
code_r0x0073084b:
        return L"ERROR_CLUSTER_WRONG_OS_VERSION";
      case 0x170c:
code_r0x00730855:
        return L"ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME";
      }
    }
    else if (param_1 < 0x17e7) {
      if (param_1 == 0x17e6) {
LAB_00730931:
        return L"ERROR_NO_BROWSER_SERVERS_FOUND";
      }
      switch(param_1) {
      case 0x1771:
code_r0x00730891:
        return L"ERROR_DECRYPTION_FAILED";
      case 0x1772:
code_r0x0073089b:
        return L"ERROR_FILE_ENCRYPTED";
      case 0x1773:
code_r0x007308a5:
        return L"ERROR_NO_RECOVERY_POLICY";
      case 0x1774:
code_r0x007308af:
        return L"ERROR_NO_EFS";
      case 0x1775:
code_r0x007308b9:
        return L"ERROR_WRONG_EFS";
      case 0x1776:
code_r0x007308c3:
        return L"ERROR_NO_USER_KEYS";
      case 0x1777:
code_r0x007308cd:
        return L"ERROR_FILE_NOT_ENCRYPTED";
      case 0x1778:
code_r0x007308d7:
        return L"ERROR_NOT_EXPORT_FORMAT";
      case 0x1779:
code_r0x007308e1:
        return L"ERROR_FILE_READ_ONLY";
      case 0x177a:
code_r0x007308eb:
        return L"ERROR_DIR_EFS_DISALLOWED";
      case 0x177b:
code_r0x007308f5:
        return L"ERROR_EFS_SERVER_NOT_TRUSTED";
      case 0x177c:
code_r0x007308ff:
        return L"ERROR_BAD_RECOVERY_POLICY";
      case 0x177d:
code_r0x00730909:
        return L"ERROR_EFS_ALG_BLOB_TOO_BIG";
      case 0x177e:
code_r0x00730913:
        return L"ERROR_VOLUME_NOT_SUPPORT_EFS";
      case 0x177f:
code_r0x0073091d:
        return L"ERROR_EFS_DISABLED";
      case 0x1780:
code_r0x00730927:
        return L"ERROR_EFS_VERSION_NOT_SUPPORT";
      }
    }
    else if (param_1 < 0x2045) {
      if (param_1 == 0x2044) goto LAB_00730eb8;
      if (param_1 < 0x200a) {
        if (param_1 == 0x2009) {
LAB_00730c5f:
          return L"ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY";
        }
        if (param_1 < 0x1b86) {
          if (param_1 == 0x1b85) {
LAB_00730afb:
            return L"ERROR_CTX_WINSTATION_ACCESS_DENIED";
          }
          if (param_1 < 0x1b67) {
            if (param_1 == 0x1b66) goto LAB_00730a49;
            if (param_1 < 0x1b60) {
              if (param_1 == 0x1b5f) {
LAB_007309ef:
                return L"ERROR_CTX_CLOSE_PENDING";
              }
              if (param_1 == 0x1838) goto LAB_007309e5;
              if (param_1 == 0x1b59) goto LAB_007309db;
              if (param_1 == 0x1b5a) goto LAB_007309d1;
              if (param_1 == 0x1b5b) goto LAB_007309c7;
              if (param_1 == 0x1b5c) goto LAB_0072a1a7;
              if (param_1 == 0x1b5d) goto LAB_007309bd;
              if (param_1 == 0x1b5e) goto LAB_007309b3;
            }
            else {
              if (param_1 == 0x1b60) {
LAB_00730a3f:
                return L"ERROR_CTX_NO_OUTBUF";
              }
              if (param_1 == 0x1b61) {
LAB_00730a35:
                return L"ERROR_CTX_MODEM_INF_NOT_FOUND";
              }
              if (param_1 == 0x1b62) {
LAB_0072a1e8:
                return L"ERROR_CTX_INVALID_MODEMNAME";
              }
              if (param_1 == 0x1b63) goto LAB_00730a2b;
              if (param_1 == 0x1b64) goto LAB_00730a21;
              if (param_1 == 0x1b65) goto code_r0x00730a17;
            }
          }
          else {
            switch(param_1) {
            case 0x1b67:
              goto code_r0x00730a6f;
            case 0x1b68:
              goto code_r0x00730a79;
            case 0x1b69:
              goto code_r0x00730a83;
            case 0x1b6e:
              goto code_r0x00730a8d;
            case 0x1b6f:
              goto code_r0x00730a97;
            case 0x1b70:
              goto code_r0x00730aa1;
            case 0x1b71:
              goto code_r0x00730aab;
            case 0x1b7b:
              goto LAB_00730ab5;
            case 0x1b7d:
              goto code_r0x00730abf;
            case 0x1b7e:
              goto code_r0x00730ac9;
            case 0x1b80:
              goto code_r0x00730ad3;
            case 0x1b81:
              goto code_r0x00730add;
            case 0x1b82:
              goto code_r0x00730ae7;
            case 0x1b84:
              goto code_r0x00730af1;
            }
          }
        }
        else if (param_1 < 0x1f42) {
          if (param_1 == 0x1f41) goto LAB_00730b8d;
          switch(param_1) {
          case 0x1b89:
            goto code_r0x00730b29;
          case 0x1b8a:
            goto code_r0x00730b33;
          case 0x1b8b:
            goto code_r0x00730b3d;
          case 0x1b8c:
            goto code_r0x00730b47;
          case 0x1b8d:
            goto code_r0x00730b51;
          case 0x1b8e:
            goto code_r0x00730b5b;
          case 0x1b8f:
            goto code_r0x00730b65;
          case 0x1b90:
            goto code_r0x00730b6f;
          case 0x1b91:
            goto code_r0x00730b79;
          case 0x1b92:
            goto code_r0x00730b83;
          }
        }
        else if (param_1 < 0x2009) {
          if (param_1 == 0x2008) goto LAB_00730c55;
          switch(param_1) {
          case 0x1f42:
            goto LAB_00730bbf;
          case 0x1f43:
            goto LAB_00730bc9;
          case 0x1f44:
            goto LAB_00730bd3;
          case 0x1f45:
code_r0x0072a257:
            return L"FRS_ERR_INTERNAL";
          case 0x1f46:
            goto LAB_00730bdd;
          case 0x1f47:
            goto code_r0x00730be7;
          case 0x1f48:
            goto code_r0x00730bf1;
          case 0x1f49:
            goto code_r0x00730bfb;
          case 0x1f4a:
            goto code_r0x00730c05;
          case 0x1f4b:
            goto code_r0x00730c0f;
          case 0x1f4c:
            goto code_r0x00730c19;
          case 0x1f4d:
            goto code_r0x00730c23;
          case 0x1f4e:
            goto code_r0x00730c2d;
          case 0x1f4f:
            goto code_r0x00730c37;
          case 0x1f50:
            goto code_r0x00730c41;
          case 0x1f51:
            goto code_r0x00730c4b;
          }
        }
      }
      else {
        switch(param_1) {
        case 0x200a:
code_r0x00730c7e:
          return L"ERROR_DS_NO_ATTRIBUTE_OR_VALUE";
        case 0x200b:
code_r0x00730c88:
          return L"ERROR_DS_INVALID_ATTRIBUTE_SYNTAX";
        case 0x200c:
code_r0x00730c92:
          return L"ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED";
        case 0x200d:
code_r0x00730c9c:
          return L"ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS";
        case 0x200e:
code_r0x00730ca6:
          return L"ERROR_DS_BUSY";
        case 0x200f:
code_r0x00730cb0:
          return L"ERROR_DS_UNAVAILABLE";
        case 0x2010:
code_r0x00730cba:
          return L"ERROR_DS_NO_RIDS_ALLOCATED";
        case 0x2011:
code_r0x00730cc4:
          return L"ERROR_DS_NO_MORE_RIDS";
        case 0x2012:
code_r0x00730cce:
          return L"ERROR_DS_INCORRECT_ROLE_OWNER";
        case 0x2013:
code_r0x00730cd8:
          return L"ERROR_DS_RIDMGR_INIT_ERROR";
        case 0x2014:
code_r0x00730ce2:
          return L"ERROR_DS_OBJ_CLASS_VIOLATION";
        case 0x2015:
code_r0x00730cec:
          return L"ERROR_DS_CANT_ON_NON_LEAF";
        case 0x2016:
code_r0x00730cf6:
          return L"ERROR_DS_CANT_ON_RDN";
        case 0x2017:
code_r0x00730d00:
          return L"ERROR_DS_CANT_MOD_OBJ_CLASS";
        case 0x2018:
code_r0x00730d0a:
          return L"ERROR_DS_CROSS_DOM_MOVE_ERROR";
        case 0x2019:
code_r0x00730d14:
          return L"ERROR_DS_GC_NOT_AVAILABLE";
        case 0x201a:
code_r0x00730d1e:
          return L"ERROR_SHARED_POLICY";
        case 0x201b:
code_r0x00730d28:
          return L"ERROR_POLICY_OBJECT_NOT_FOUND";
        case 0x201c:
code_r0x00730d32:
          return L"ERROR_POLICY_ONLY_IN_DS";
        case 0x201d:
code_r0x00730d3c:
          return L"ERROR_PROMOTION_ACTIVE";
        case 0x201e:
code_r0x00730d46:
          return L"ERROR_NO_PROMOTION_ACTIVE";
        case 0x2020:
code_r0x00730d50:
          return L"ERROR_DS_OPERATIONS_ERROR";
        case 0x2021:
code_r0x00730d5a:
          return L"ERROR_DS_PROTOCOL_ERROR";
        case 0x2022:
code_r0x00730d64:
          return L"ERROR_DS_TIMELIMIT_EXCEEDED";
        case 0x2023:
code_r0x00730d6e:
          return L"ERROR_DS_SIZELIMIT_EXCEEDED";
        case 0x2024:
code_r0x00730d78:
          return L"ERROR_DS_ADMIN_LIMIT_EXCEEDED";
        case 0x2025:
code_r0x00730d82:
          return L"ERROR_DS_COMPARE_FALSE";
        case 0x2026:
code_r0x00730d8c:
          return L"ERROR_DS_COMPARE_TRUE";
        case 0x2027:
code_r0x00730d96:
          return L"ERROR_DS_AUTH_METHOD_NOT_SUPPORTED";
        case 0x2028:
code_r0x00730da0:
          return L"ERROR_DS_STRONG_AUTH_REQUIRED";
        case 0x2029:
code_r0x00730daa:
          return L"ERROR_DS_INAPPROPRIATE_AUTH";
        case 0x202a:
          goto LAB_00730db4;
        case 0x202b:
          goto code_r0x00730dbe;
        case 0x202c:
          goto code_r0x00730dc8;
        case 0x202d:
          goto code_r0x00730dd2;
        case 0x202e:
          goto code_r0x00730ddc;
        case 0x202f:
          goto code_r0x00730de6;
        case 0x2030:
          goto code_r0x00730df0;
        case 0x2031:
          goto code_r0x00730dfa;
        case 0x2032:
          goto code_r0x00730e04;
        case 0x2033:
          goto code_r0x00730e0e;
        case 0x2034:
          goto code_r0x00730e18;
        case 0x2035:
          goto code_r0x00730e22;
        case 0x2036:
          goto code_r0x00730e2c;
        case 0x2037:
          goto code_r0x00730e36;
        case 0x2038:
          goto code_r0x00730e40;
        case 0x2039:
          goto code_r0x00730e4a;
        case 0x203a:
          goto code_r0x00730e54;
        case 0x203b:
          goto code_r0x00730e5e;
        case 0x203c:
          goto code_r0x00730e68;
        case 0x203d:
          goto code_r0x00730e72;
        case 0x203e:
          goto code_r0x00730e7c;
        case 0x203f:
          goto code_r0x00730e86;
        case 0x2040:
          goto code_r0x00730e90;
        case 0x2041:
          goto code_r0x00730e9a;
        case 0x2042:
          goto code_r0x00730ea4;
        case 0x2043:
          goto code_r0x00730eae;
        }
      }
    }
    else {
      switch(param_1) {
      case 0x2045:
        goto code_r0x00731343;
      case 0x2046:
        goto code_r0x0073134d;
      case 0x206d:
        goto code_r0x00730ed9;
      case 0x206e:
        goto code_r0x00730ee3;
      case 0x206f:
        goto code_r0x00730eed;
      case 0x2070:
        goto code_r0x00730ef7;
      case 0x2071:
        goto code_r0x00730f01;
      case 0x2072:
        goto code_r0x00730f0b;
      case 0x2073:
        goto code_r0x00730f15;
      case 0x2074:
        goto code_r0x00730f1f;
      case 0x2075:
        goto code_r0x00730f29;
      case 0x2076:
        goto code_r0x00730f33;
      case 0x2077:
        goto code_r0x00730f3d;
      case 0x2078:
        goto code_r0x00730f47;
      case 0x2079:
        goto code_r0x00730f51;
      case 0x207a:
        goto code_r0x00730f5b;
      case 0x207b:
        goto code_r0x00730f65;
      case 0x207c:
        goto code_r0x00730f6f;
      case 0x207d:
        goto code_r0x00730f79;
      case 0x207e:
        goto code_r0x00730f83;
      case 0x2080:
        goto code_r0x00730f8d;
      case 0x2081:
        goto code_r0x00730f97;
      case 0x2082:
        goto code_r0x00730fa1;
      case 0x2083:
        goto code_r0x00730fab;
      case 0x2084:
        goto code_r0x00730fb5;
      case 0x2085:
        goto code_r0x00730fbf;
      case 0x2086:
        goto code_r0x00730fc9;
      case 0x2087:
        goto code_r0x00730fd3;
      case 0x2088:
        goto code_r0x00730fdd;
      case 0x2089:
        goto code_r0x00730fe7;
      case 0x208a:
        goto code_r0x00730ff1;
      case 0x208b:
        goto code_r0x00730ffb;
      case 0x208c:
        goto code_r0x00731005;
      case 0x208d:
        goto code_r0x0073100f;
      case 0x208e:
        goto code_r0x00731019;
      case 0x208f:
        goto code_r0x00731023;
      case 0x2090:
        goto code_r0x0073102d;
      case 0x2091:
        goto code_r0x00731037;
      case 0x2092:
        goto code_r0x00731041;
      case 0x2093:
        goto code_r0x00731357;
      case 0x2094:
        goto code_r0x0073104b;
      case 0x2095:
        goto code_r0x00731055;
      case 0x2096:
        goto code_r0x0073105f;
      case 0x2097:
        goto code_r0x00731069;
      case 0x2098:
        goto code_r0x00731073;
      case 0x2099:
        goto code_r0x0073107d;
      case 0x209a:
        goto code_r0x00731087;
      case 0x209b:
        goto code_r0x00731091;
      case 0x209c:
        goto code_r0x0073109b;
      case 0x209d:
        goto code_r0x007310a5;
      case 0x209e:
        goto code_r0x007310af;
      case 0x209f:
        goto code_r0x007310b9;
      case 0x20a0:
        goto code_r0x007310c3;
      case 0x20a1:
        goto code_r0x007310cd;
      case 0x20a2:
        goto code_r0x007310d7;
      case 0x20a3:
        goto code_r0x007310e1;
      case 0x20a4:
        goto code_r0x007310eb;
      case 0x20a5:
        goto code_r0x007310f5;
      case 0x20a6:
        goto code_r0x007310ff;
      case 0x20a7:
        goto code_r0x00731109;
      case 0x20a8:
        goto code_r0x00731113;
      case 0x20a9:
        goto code_r0x0073111d;
      case 0x20aa:
        goto code_r0x00731127;
      case 0x20ab:
        goto code_r0x00731131;
      case 0x20ac:
        goto code_r0x0073113b;
      case 0x20ad:
        goto code_r0x00731145;
      case 0x20ae:
        goto code_r0x0073114f;
      case 0x20af:
        goto code_r0x00731159;
      case 0x20b0:
        goto code_r0x00731163;
      case 0x20b1:
        goto code_r0x0073116d;
      case 0x20b2:
        goto code_r0x00731177;
      case 0x20b3:
        goto code_r0x00731181;
      case 0x20b4:
        goto code_r0x0073118b;
      case 0x20b5:
        goto code_r0x00731195;
      case 0x20b6:
        goto code_r0x0073119f;
      case 0x20b7:
        goto code_r0x007311a9;
      case 0x20b8:
        goto code_r0x007311b3;
      case 0x20b9:
        goto code_r0x007311bd;
      case 0x20ba:
        goto code_r0x007311c7;
      case 0x20bb:
        goto code_r0x007311d1;
      case 0x20bc:
        goto code_r0x007311db;
      case 0x20bd:
        goto code_r0x007311e5;
      case 0x20be:
        goto code_r0x007311ef;
      case 0x20bf:
        goto code_r0x007311f9;
      case 0x20c0:
        goto code_r0x00731203;
      case 0x20c1:
        goto code_r0x0073120d;
      case 0x20c2:
        goto code_r0x00731217;
      case 0x20c3:
        goto code_r0x00731221;
      case 0x20c4:
        goto code_r0x0073122b;
      case 0x20c5:
        goto code_r0x00731235;
      case 0x20c6:
        goto code_r0x0073123f;
      case 0x20c7:
        goto code_r0x00731249;
      case 0x20c8:
        goto code_r0x00731253;
      case 0x20c9:
        goto code_r0x0073125d;
      case 0x20ca:
        goto code_r0x00731267;
      case 0x20cb:
        goto code_r0x00731271;
      case 0x20cc:
        goto code_r0x0073127b;
      case 0x20cd:
        goto code_r0x00731285;
      case 0x20ce:
        goto code_r0x0073128f;
      case 0x20cf:
        goto code_r0x00731299;
      case 0x20d0:
        goto code_r0x007312a3;
      case 0x20d1:
        goto code_r0x007312ad;
      case 0x20d2:
        goto code_r0x007312b7;
      case 0x20d3:
        goto code_r0x007312c1;
      case 0x20d4:
        goto code_r0x007312cb;
      case 0x20d5:
        goto code_r0x007312d5;
      case 0x20d6:
        goto code_r0x007312df;
      case 0x20d7:
        goto code_r0x007312e9;
      case 0x20d8:
        goto code_r0x007312f3;
      case 0x20d9:
        goto code_r0x007312fd;
      case 0x20da:
        goto code_r0x00731307;
      case 0x20db:
        goto code_r0x00731311;
      case 0x20dc:
        goto code_r0x0073131b;
      case 0x20dd:
        goto code_r0x00731325;
      case 0x20de:
        goto code_r0x0073132f;
      case 0x20df:
        goto code_r0x00731339;
      }
    }
  }
  else if (param_1 < 0x2329) {
    if (param_1 == 9000) goto LAB_00731acf;
    switch(param_1) {
    case 0x20e1:
      goto code_r0x00731395;
    case 0x20e2:
      goto code_r0x0073139f;
    case 0x20e3:
      goto code_r0x007313a9;
    case 0x20e4:
      goto code_r0x007313b3;
    case 0x20e5:
      goto code_r0x007313bd;
    case 0x20e6:
      goto code_r0x007313c7;
    case 0x20e7:
      goto code_r0x007313d1;
    case 0x20e8:
      goto code_r0x007313db;
    case 0x20e9:
      goto code_r0x007313e5;
    case 0x20ea:
      goto code_r0x007313ef;
    case 0x20eb:
      goto code_r0x007313f9;
    case 0x20ec:
      goto code_r0x00731403;
    case 0x20ed:
      goto code_r0x0073140d;
    case 0x20ee:
      goto code_r0x00731417;
    case 0x20ef:
      goto code_r0x00731421;
    case 0x20f0:
      goto code_r0x0073142b;
    case 0x20f1:
      goto code_r0x00731435;
    case 0x20f2:
      goto code_r0x0073143f;
    case 0x20f3:
      goto code_r0x00731449;
    case 0x20f4:
      goto code_r0x00731453;
    case 0x20f5:
      goto code_r0x0073145d;
    case 0x20f6:
      goto code_r0x00731467;
    case 0x20f7:
      goto code_r0x00731471;
    case 0x20f8:
      goto code_r0x0073147b;
    case 0x20f9:
      goto code_r0x00731485;
    case 0x20fa:
      goto code_r0x0073148f;
    case 0x20fb:
      goto code_r0x00731499;
    case 0x20fc:
      goto code_r0x007314a3;
    case 0x20fd:
      goto code_r0x007314ad;
    case 0x20fe:
      goto code_r0x007314b7;
    case 0x20ff:
      goto code_r0x007314c1;
    case 0x2100:
      goto code_r0x007314cb;
    case 0x2101:
      goto code_r0x007314d5;
    case 0x2102:
      goto code_r0x007314df;
    case 0x2103:
      goto code_r0x007314e9;
    case 0x2104:
      goto code_r0x007314f3;
    case 0x2105:
      goto code_r0x007314fd;
    case 0x2106:
      goto code_r0x00731507;
    case 0x2107:
      goto code_r0x00731511;
    case 0x2108:
      goto code_r0x0073151b;
    case 0x2109:
      goto code_r0x00731525;
    case 0x210a:
      goto code_r0x0073152f;
    case 0x210b:
      goto code_r0x00731539;
    case 0x210c:
      goto code_r0x00731543;
    case 0x210d:
      goto code_r0x0073154d;
    case 0x210e:
      goto code_r0x00731557;
    case 0x210f:
      goto code_r0x00731561;
    case 0x2110:
      goto code_r0x0073156b;
    case 0x2111:
      goto code_r0x00731575;
    case 0x2112:
      goto code_r0x0073157f;
    case 0x2113:
      goto code_r0x00731589;
    case 0x2114:
      goto code_r0x00731593;
    case 0x2115:
      goto code_r0x0073159d;
    case 0x2116:
      goto code_r0x007315a7;
    case 0x2117:
      goto code_r0x007315b1;
    case 0x2118:
      goto code_r0x007315bb;
    case 0x2119:
      goto code_r0x007315c5;
    case 0x211a:
      goto code_r0x007315cf;
    case 0x211b:
      goto code_r0x007315d9;
    case 0x211c:
      goto code_r0x007315e3;
    case 0x211d:
      goto code_r0x007315ed;
    case 0x211e:
      goto code_r0x007315f7;
    case 0x211f:
      goto code_r0x00731601;
    case 0x2120:
      goto code_r0x0073160b;
    case 0x2121:
      goto code_r0x00731615;
    case 0x2122:
      goto code_r0x0073161f;
    case 0x2123:
      goto code_r0x00731629;
    case 0x2124:
      goto code_r0x00731633;
    case 0x2125:
      goto code_r0x0073163d;
    case 0x2126:
      goto code_r0x00731647;
    case 0x2127:
      goto code_r0x00731651;
    case 0x2128:
      goto code_r0x0073165b;
    case 0x2129:
      goto code_r0x00731665;
    case 0x212a:
      goto code_r0x0073166f;
    case 0x212b:
      goto code_r0x00731679;
    case 0x212c:
      goto code_r0x00731683;
    case 0x212d:
      goto code_r0x0073168d;
    case 0x212e:
      goto code_r0x00731697;
    case 0x212f:
      goto code_r0x007316a1;
    case 0x2130:
      goto code_r0x007316ab;
    case 0x2131:
      goto code_r0x007316b5;
    case 0x2132:
      goto code_r0x007316bf;
    case 0x2133:
      goto code_r0x007316c9;
    case 0x2134:
      goto code_r0x007316d3;
    case 0x2135:
      goto code_r0x007316dd;
    case 0x2136:
      goto code_r0x007316e7;
    case 0x2137:
      goto code_r0x007316f1;
    case 0x2138:
      goto code_r0x007316fb;
    case 0x2139:
      goto code_r0x00731705;
    case 0x213a:
      goto code_r0x0073170f;
    case 0x213b:
      goto code_r0x00731719;
    case 0x213c:
      goto code_r0x00731723;
    case 0x213d:
      goto code_r0x0073172d;
    case 0x213e:
      goto code_r0x00731737;
    case 0x213f:
      goto code_r0x00731741;
    case 0x2140:
      goto code_r0x0073174b;
    case 0x2141:
      goto code_r0x00731755;
    case 0x2142:
      goto code_r0x0073175f;
    case 0x2143:
      goto code_r0x00731769;
    case 0x2144:
      goto code_r0x00731773;
    case 0x2145:
      goto code_r0x0073177d;
    case 0x2146:
      goto code_r0x00731787;
    case 0x2147:
      goto code_r0x00731791;
    case 0x2148:
      goto code_r0x0073179b;
    case 0x2149:
      goto code_r0x007317a5;
    case 0x214a:
      goto code_r0x007317af;
    case 0x214b:
      goto code_r0x007317b9;
    case 0x214c:
      goto code_r0x007317c3;
    case 0x214d:
      goto code_r0x007317cd;
    case 0x214e:
      goto code_r0x007317d7;
    case 0x214f:
      goto code_r0x007317e1;
    case 0x2150:
      goto code_r0x007317eb;
    case 0x2151:
      goto code_r0x007317f5;
    case 0x2152:
      goto code_r0x007317ff;
    case 0x2153:
      goto code_r0x00731809;
    case 0x2154:
      goto code_r0x00731813;
    case 0x2155:
      goto code_r0x0073181d;
    case 0x2156:
      goto code_r0x00731827;
    case 0x2157:
      goto code_r0x00731831;
    case 0x2158:
      goto code_r0x0073183b;
    case 0x2159:
      goto code_r0x00731845;
    case 0x215a:
      goto code_r0x0073184f;
    case 0x215b:
      goto code_r0x00731859;
    case 0x215c:
      goto code_r0x00731863;
    case 0x215d:
      goto code_r0x0073186d;
    case 0x215e:
      goto code_r0x00731877;
    case 0x215f:
      goto code_r0x00731881;
    case 0x2160:
      goto code_r0x0073188b;
    case 0x2161:
      goto code_r0x00731895;
    case 0x2162:
      goto code_r0x0073189f;
    case 0x2163:
      goto code_r0x007318a9;
    case 0x2164:
      goto code_r0x007318b3;
    case 0x2165:
      goto code_r0x007318bd;
    case 0x2166:
      goto code_r0x007318c7;
    case 0x2167:
      goto code_r0x007318d1;
    case 0x2168:
      goto code_r0x007318db;
    case 0x2169:
      goto code_r0x007318e5;
    case 0x216a:
      goto code_r0x007318ef;
    case 0x216b:
      goto code_r0x007318f9;
    case 0x216c:
      goto code_r0x00731903;
    case 0x216d:
      goto code_r0x0073190d;
    case 0x216e:
      goto code_r0x00731917;
    case 0x216f:
      goto code_r0x00731921;
    case 0x2170:
      goto code_r0x0073192b;
    case 0x2171:
      goto code_r0x00731935;
    case 0x2172:
      goto code_r0x0073193f;
    case 0x2173:
      goto code_r0x00731949;
    case 0x2174:
      goto code_r0x00731953;
    case 0x2175:
      goto code_r0x0073195d;
    case 0x2176:
      goto code_r0x00731967;
    case 0x2177:
      goto code_r0x00731971;
    case 0x2178:
      goto code_r0x0073197b;
    case 0x2179:
      goto code_r0x00731985;
    case 0x217a:
      goto code_r0x0073198f;
    case 0x217b:
      goto code_r0x00731999;
    case 0x217c:
      goto LAB_007319a3;
    case 0x217d:
      goto code_r0x007319ad;
    case 0x217e:
      goto code_r0x007319b7;
    case 0x217f:
      goto code_r0x007319c1;
    case 0x2180:
      goto code_r0x007319cb;
    case 0x2181:
      goto code_r0x007319d5;
    case 0x2182:
      goto code_r0x007319df;
    case 0x2183:
      goto code_r0x007319e9;
    case 0x2184:
      goto code_r0x007319f3;
    case 0x2185:
      goto code_r0x007319fd;
    case 0x2186:
      goto code_r0x00731a07;
    case 0x2187:
      goto code_r0x00731a11;
    case 0x2188:
      goto code_r0x00731a1b;
    case 0x2189:
      goto code_r0x00731a25;
    case 0x218a:
      goto code_r0x00731a2f;
    case 0x218b:
      goto code_r0x00731a39;
    case 0x218c:
      goto code_r0x00731a43;
    case 0x218d:
      goto code_r0x00731a4d;
    case 0x218e:
      goto code_r0x00731a57;
    case 0x218f:
      goto code_r0x00731a61;
    case 0x2190:
      goto code_r0x00731a6b;
    case 0x2191:
      goto code_r0x00731a75;
    case 0x2192:
      goto code_r0x00731a7f;
    case 0x2193:
      goto code_r0x00731a89;
    case 0x2194:
      goto code_r0x00731a93;
    case 0x2195:
      goto code_r0x00731a9d;
    case 0x2196:
      goto code_r0x00731aa7;
    case 0x2197:
      goto code_r0x00731ab1;
    case 0x2198:
      goto code_r0x00731abb;
    case 0x2199:
      goto code_r0x00731ac5;
    }
  }
  else if (param_1 < 0x251d) {
    if (param_1 == 0x251c) goto LAB_00731b83;
    switch(param_1) {
    case 0x2329:
      goto code_r0x00731b01;
    case 0x232a:
      goto code_r0x00731b0b;
    case 0x232b:
      goto code_r0x00731b15;
    case 0x232c:
      goto code_r0x00731b1f;
    case 0x232d:
      goto code_r0x00731b29;
    case 0x232e:
      goto code_r0x00731b33;
    case 0x232f:
      goto code_r0x00731b3d;
    case 0x2330:
      goto code_r0x00731b47;
    case 0x2331:
      goto code_r0x00731b51;
    case 0x2332:
      goto code_r0x00731b5b;
    case 0x2338:
      goto code_r0x00731b65;
    case 0x2339:
      goto code_r0x00731b6f;
    case 0x233a:
      goto code_r0x00731b79;
    }
  }
  else if (param_1 < 0x3622) {
    if (param_1 == 0x3621) {
LAB_00732707:
      return L"ERROR_IPSEC_IKE_GETSPIFAIL";
    }
    if (param_1 < 0x2779) {
      if (param_1 == 0x2778) {
LAB_00732120:
        return L"WSAEINVALIDPROCTABLE";
      }
      if (param_1 < 0x25f8) {
        if (param_1 == 0x25f7) {
LAB_00731e28:
          return L"DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE";
        }
        switch(param_1) {
        case 0x251d:
code_r0x00731be4:
          return L"DNS_INFO_NO_RECORDS";
        case 0x251e:
code_r0x00731bee:
          return L"DNS_ERROR_BAD_PACKET";
        case 0x251f:
code_r0x00731bf8:
          return L"DNS_ERROR_NO_PACKET";
        case 0x2520:
code_r0x00731c02:
          return L"DNS_ERROR_RCODE";
        case 0x2521:
code_r0x00731c0c:
          return L"DNS_ERROR_UNSECURE_PACKET";
        case 0x254e:
code_r0x00731c16:
          return L"DNS_ERROR_GENERAL_API_BASE";
        case 0x254f:
code_r0x00731c20:
          return L"DNS_ERROR_INVALID_TYPE";
        case 0x2550:
code_r0x00731c2a:
          return L"DNS_ERROR_INVALID_IP_ADDRESS";
        case 0x2551:
code_r0x00731c34:
          return L"DNS_ERROR_INVALID_PROPERTY";
        case 0x2552:
code_r0x00731c3e:
          return L"DNS_ERROR_TRY_AGAIN_LATER";
        case 0x2553:
code_r0x00731c48:
          return L"DNS_ERROR_NOT_UNIQUE";
        case 0x2554:
code_r0x00731c52:
          return L"DNS_ERROR_NON_RFC_NAME";
        case 0x2555:
code_r0x00731c5c:
          return L"DNS_STATUS_FQDN";
        case 0x2556:
code_r0x00731c66:
          return L"DNS_STATUS_DOTTED_NAME";
        case 0x2557:
code_r0x00731c70:
          return L"DNS_STATUS_SINGLE_PART_NAME";
        case 0x2580:
code_r0x00731c7a:
          return L"DNS_ERROR_ZONE_BASE";
        case 0x2581:
code_r0x00731c84:
          return L"DNS_ERROR_ZONE_DOES_NOT_EXIST";
        case 0x2582:
code_r0x00731c8e:
          return L"DNS_ERROR_NO_ZONE_INFO";
        case 0x2583:
code_r0x00731c98:
          return L"DNS_ERROR_INVALID_ZONE_OPERATION";
        case 0x2584:
code_r0x00731ca2:
          return L"DNS_ERROR_ZONE_CONFIGURATION_ERROR";
        case 0x2585:
code_r0x00731cac:
          return L"DNS_ERROR_ZONE_HAS_NO_SOA_RECORD";
        case 0x2586:
code_r0x00731cb6:
          return L"DNS_ERROR_ZONE_HAS_NO_NS_RECORDS";
        case 0x2587:
code_r0x00731cc0:
          return L"DNS_ERROR_ZONE_LOCKED";
        case 0x2588:
code_r0x00731cca:
          return L"DNS_ERROR_ZONE_CREATION_FAILED";
        case 0x2589:
code_r0x00731cd4:
          return L"DNS_ERROR_ZONE_ALREADY_EXISTS";
        case 0x258a:
code_r0x00731cde:
          return L"DNS_ERROR_AUTOZONE_ALREADY_EXISTS";
        case 0x258b:
code_r0x00731ce8:
          return L"DNS_ERROR_INVALID_ZONE_TYPE";
        case 0x258c:
code_r0x00731cf2:
          return L"DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP";
        case 0x258d:
code_r0x00731cfc:
          return L"DNS_ERROR_ZONE_NOT_SECONDARY";
        case 0x258e:
code_r0x00731d06:
          return L"DNS_ERROR_NEED_SECONDARY_ADDRESSES";
        case 0x258f:
code_r0x00731d10:
          return L"DNS_ERROR_WINS_INIT_FAILED";
        case 0x2590:
code_r0x00731d1a:
          return L"DNS_ERROR_NEED_WINS_SERVERS";
        case 0x2591:
code_r0x00731d24:
          return L"DNS_ERROR_NBSTAT_INIT_FAILED";
        case 0x2592:
code_r0x00731d2e:
          return L"DNS_ERROR_SOA_DELETE_INVALID";
        case 0x25b2:
LAB_00731d38:
          return L"DNS_ERROR_DATAFILE_BASE";
        case 0x25b3:
LAB_00731d42:
          return L"DNS_ERROR_PRIMARY_REQUIRES_DATAFILE";
        case 0x25b4:
LAB_00731d4c:
          return L"DNS_ERROR_INVALID_DATAFILE_NAME";
        case 0x25b5:
LAB_00731d56:
          return L"DNS_ERROR_DATAFILE_OPEN_FAILURE";
        case 0x25b6:
LAB_00731d60:
          return L"DNS_ERROR_FILE_WRITEBACK_FAILED";
        case 0x25b7:
LAB_00731d6a:
          return L"DNS_ERROR_DATAFILE_PARSING";
        case 0x25e4:
LAB_00731d74:
          return L"DNS_ERROR_DATABASE_BASE";
        case 0x25e5:
LAB_00731d7e:
          return L"DNS_ERROR_RECORD_DOES_NOT_EXIST";
        case 0x25e6:
LAB_00731d88:
          return L"DNS_ERROR_RECORD_FORMAT";
        case 0x25e7:
LAB_00731d92:
          return L"DNS_ERROR_NODE_CREATION_FAILED";
        case 0x25e8:
LAB_00731d9c:
          return L"DNS_ERROR_UNKNOWN_RECORD_TYPE";
        case 0x25e9:
LAB_00731da6:
          return L"DNS_ERROR_RECORD_TIMED_OUT";
        case 0x25ea:
LAB_00731db0:
          return L"DNS_ERROR_NAME_NOT_IN_ZONE";
        case 0x25eb:
LAB_00731dba:
          return L"DNS_ERROR_CNAME_LOOP";
        case 0x25ec:
LAB_00731dc4:
          return L"DNS_ERROR_NODE_IS_CNAME";
        case 0x25ed:
LAB_00731dce:
          return L"DNS_ERROR_CNAME_COLLISION";
        case 0x25ee:
LAB_00731dd8:
          return L"DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT";
        case 0x25ef:
LAB_00731de2:
          return L"DNS_ERROR_RECORD_ALREADY_EXISTS";
        case 0x25f0:
LAB_00731dec:
          return L"DNS_ERROR_SECONDARY_DATA";
        case 0x25f1:
LAB_00731df6:
          return L"DNS_ERROR_NO_CREATE_CACHE_DATA";
        case 0x25f2:
LAB_00731e00:
          return L"DNS_ERROR_NAME_DOES_NOT_EXIST";
        case 0x25f3:
LAB_00731e0a:
          return L"DNS_WARNING_PTR_CREATE_FAILED";
        case 0x25f4:
code_r0x0072a3d0:
          return L"DNS_WARNING_DOMAIN_UNDELETED";
        case 0x25f5:
LAB_00731e14:
          return L"DNS_ERROR_DS_UNAVAILABLE";
        case 0x25f6:
LAB_00731e1e:
          return L"DNS_ERROR_DS_ZONE_ALREADY_EXISTS";
        }
      }
      else if (param_1 < 0x2741) {
        if (param_1 == 0x2740) {
LAB_00731fd8:
          return L"WSAEADDRINUSE";
        }
        if (param_1 < 0x2727) {
          if (param_1 == 0x2726) goto LAB_00731f26;
          if (param_1 < 0x267c) {
            if (param_1 == 0x267b) {
LAB_00731ec2:
              return L"DNS_ERROR_NO_TCPIP";
            }
            if (param_1 == 0x2616) {
LAB_0072a3fb:
              return L"DNS_ERROR_OPERATION_BASE";
            }
            if (param_1 == 0x2617) goto LAB_00731eb8;
            if (param_1 == 0x2618) goto LAB_00731eae;
            if (param_1 == 0x2619) goto LAB_00731ea4;
            if (param_1 == 0x2648) goto LAB_00731e9a;
            if (param_1 == 0x2649) goto LAB_00731e90;
            if (param_1 == 0x267a) goto LAB_00731e86;
          }
          else {
            if (param_1 == 0x267c) {
LAB_0072a452:
              return L"DNS_ERROR_NO_DNS_SERVERS";
            }
            if (param_1 == 10000) goto LAB_00731f1c;
            if (param_1 == 0x2714) goto LAB_00731f12;
            if (param_1 == 0x2719) goto LAB_00731f08;
            if (param_1 == 0x271d) goto LAB_00731efe;
            if (param_1 == 0x271e) goto code_r0x00731ef4;
          }
        }
        else {
          switch(param_1) {
          case 0x2728:
            goto code_r0x00731f4c;
          case 0x2733:
            goto code_r0x00731f56;
          case 0x2734:
            goto code_r0x00731f60;
          case 0x2735:
            goto code_r0x00731f6a;
          case 0x2736:
            goto code_r0x00731f74;
          case 0x2737:
            goto code_r0x00731f7e;
          case 0x2738:
            goto code_r0x00731f88;
          case 0x2739:
            goto code_r0x00731f92;
          case 0x273a:
            goto code_r0x00731f9c;
          case 0x273b:
            goto code_r0x00731fa6;
          case 0x273c:
            goto code_r0x00731fb0;
          case 0x273d:
            goto code_r0x00731fba;
          case 0x273e:
            goto code_r0x00731fc4;
          case 0x273f:
            goto code_r0x00731fce;
          }
        }
      }
      else {
        switch(param_1) {
        case 0x2741:
code_r0x00731ffe:
          return L"WSAEADDRNOTAVAIL";
        case 0x2742:
code_r0x00732008:
          return L"WSAENETDOWN";
        case 0x2743:
code_r0x00732012:
          return L"WSAENETUNREACH";
        case 0x2744:
code_r0x0073201c:
          return L"WSAENETRESET";
        case 0x2745:
code_r0x00732026:
          return L"WSAECONNABORTED";
        case 0x2746:
code_r0x00732030:
          return L"WSAECONNRESET";
        case 0x2747:
code_r0x0073203a:
          return L"WSAENOBUFS";
        case 0x2748:
code_r0x00732044:
          return L"WSAEISCONN";
        case 0x2749:
code_r0x0073204e:
          return L"WSAENOTCONN";
        case 0x274a:
code_r0x00732058:
          return L"WSAESHUTDOWN";
        case 0x274b:
code_r0x00732062:
          return L"WSAETOOMANYREFS";
        case 0x274c:
code_r0x0073206c:
          return L"WSAETIMEDOUT";
        case 0x274d:
code_r0x00732076:
          return L"WSAECONNREFUSED";
        case 0x274e:
code_r0x00732080:
          return L"WSAELOOP";
        case 0x274f:
          goto LAB_0073208a;
        case 0x2750:
LAB_00732094:
          return L"WSAEHOSTDOWN";
        case 0x2751:
LAB_0073209e:
          return L"WSAEHOSTUNREACH";
        case 0x2752:
LAB_007320a8:
          return L"WSAENOTEMPTY";
        case 0x2753:
LAB_007320b2:
          return L"WSAEPROCLIM";
        case 0x2754:
LAB_007320bc:
          return L"WSAEUSERS";
        case 0x2755:
LAB_007320c6:
          return L"WSAEDQUOT";
        case 0x2756:
LAB_007320d0:
          return L"WSAESTALE";
        case 0x2757:
LAB_007320da:
          return L"WSAEREMOTE";
        case 0x276b:
LAB_007320e4:
          return L"WSASYSNOTREADY";
        case 0x276c:
LAB_007320ee:
          return L"WSAVERNOTSUPPORTED";
        case 0x276d:
LAB_007320f8:
          return L"WSANOTINITIALISED";
        case 0x2775:
LAB_00732102:
          return L"WSAEDISCON";
        case 0x2776:
LAB_0073210c:
          return L"WSAENOMORE";
        case 0x2777:
LAB_00732116:
          return L"WSAECANCELLED";
        }
      }
    }
    else if (param_1 < 0x32dd) {
      if (param_1 == 0x32dc) {
LAB_00732425:
        return L"ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION";
      }
      if (param_1 < 0x2b0f) {
        if (param_1 == 0x2b0e) goto LAB_007322c4;
        if (param_1 < 0x2b00) {
          if (param_1 == 0x2aff) {
LAB_00732223:
            return L"WSA_QOS_NO_SENDERS";
          }
          if (param_1 < 0x2781) {
            if (param_1 == 0x2780) goto LAB_007321c9;
            if (param_1 == 0x2779) goto LAB_007321bf;
            if (param_1 == 0x277a) goto LAB_007321b5;
            if (param_1 == 0x277b) goto LAB_007321ab;
            if (param_1 == 0x277c) goto LAB_007321a1;
            if (param_1 == 0x277d) goto LAB_00732197;
            if (param_1 == 0x277e) goto LAB_0072a4fc;
            if (param_1 == 0x277f) goto LAB_0073218d;
          }
          else {
            if (param_1 == 0x2af9) {
LAB_00732219:
              return L"WSAHOST_NOT_FOUND";
            }
            if (param_1 == 0x2afa) {
LAB_0072a527:
              return L"WSATRY_AGAIN";
            }
            if (param_1 == 0x2afb) goto LAB_0073220f;
            if (param_1 == 0x2afc) goto LAB_00732205;
            if (param_1 == 0x2afd) goto LAB_007321fb;
            if (param_1 == 0x2afe) goto LAB_007321f1;
          }
        }
        else {
          switch(param_1) {
          case 0x2b00:
LAB_00732242:
            return L"WSA_QOS_NO_RECEIVERS";
          case 0x2b01:
LAB_0073224c:
            return L"WSA_QOS_REQUEST_CONFIRMED";
          case 0x2b02:
code_r0x0072a57e:
            return L"WSA_QOS_ADMISSION_FAILURE";
          case 0x2b03:
            goto LAB_00732256;
          case 0x2b04:
            goto code_r0x00732260;
          case 0x2b05:
            goto code_r0x0073226a;
          case 0x2b06:
            goto code_r0x00732274;
          case 0x2b07:
            goto code_r0x0073227e;
          case 0x2b08:
            goto code_r0x00732288;
          case 0x2b09:
            goto code_r0x00732292;
          case 0x2b0a:
            goto code_r0x0073229c;
          case 0x2b0b:
            goto code_r0x007322a6;
          case 0x2b0c:
            goto code_r0x007322b0;
          case 0x2b0d:
            goto code_r0x007322ba;
          }
        }
      }
      else if (param_1 < 0x32c9) {
        if (param_1 == 13000) goto LAB_00732348;
        switch(param_1) {
        case 0x2b0f:
          goto code_r0x007322ee;
        case 0x2b10:
          goto code_r0x007322f8;
        case 0x2b11:
          goto code_r0x00732302;
        case 0x2b12:
          goto code_r0x0073230c;
        case 0x2b13:
          goto code_r0x00732316;
        case 0x2b14:
          goto code_r0x00732320;
        case 0x2b15:
          goto code_r0x0073232a;
        case 0x2b16:
          goto code_r0x00732334;
        case 0x2b17:
          goto code_r0x0073233e;
        }
      }
      else {
        switch(param_1) {
        case 0x32c9:
          goto code_r0x00732367;
        case 0x32ca:
          goto code_r0x00732371;
        case 0x32cb:
          goto code_r0x0073237b;
        case 0x32cc:
          goto code_r0x00732385;
        case 0x32cd:
          goto code_r0x0073238f;
        case 0x32ce:
          goto code_r0x00732399;
        case 0x32cf:
          goto code_r0x007323a3;
        case 0x32d0:
          goto code_r0x007323ad;
        case 0x32d1:
          goto code_r0x007323b7;
        case 0x32d2:
          goto code_r0x007323c1;
        case 0x32d3:
          goto code_r0x007323cb;
        case 0x32d4:
          goto code_r0x007323d5;
        case 0x32d5:
          goto code_r0x007323df;
        case 0x32d6:
          goto code_r0x007323e9;
        case 0x32d7:
          goto code_r0x007323f3;
        case 0x32d8:
          goto code_r0x007323fd;
        case 0x32d9:
          goto code_r0x00732407;
        case 0x32da:
          goto code_r0x00732411;
        case 0x32db:
          goto code_r0x0073241b;
        }
      }
    }
    else if (param_1 < 0x3605) {
      if (param_1 == 0x3604) goto LAB_007325d0;
      if (param_1 < 0x35f4) {
        if (param_1 == 0x35f3) goto LAB_00732525;
        if (param_1 < 0x35ed) {
          if (param_1 == 0x35ec) goto LAB_007324c5;
          if (param_1 == 0x32dd) goto LAB_007324bb;
          if (param_1 == 0x32de) goto LAB_007324b1;
          if (param_1 == 0x32df) goto LAB_007324a7;
          if (param_1 == 0x35e8) goto LAB_0073249d;
          if (param_1 == 0x35e9) goto LAB_00732493;
          if (param_1 == 0x35ea) goto LAB_00732489;
          if (param_1 == 0x35eb) goto code_r0x0073247f;
        }
        else {
          if (param_1 == 0x35ed) goto LAB_0073251b;
          if (param_1 == 0x35ee) goto LAB_00732511;
          if (param_1 == 0x35ef) goto LAB_00732507;
          if (param_1 == 0x35f0) goto LAB_007324fd;
          if (param_1 == 0x35f1) goto LAB_007324f3;
          if (param_1 == 0x35f2) goto code_r0x007324e9;
        }
      }
      else {
        switch(param_1) {
        case 0x35f4:
          goto code_r0x00732544;
        case 0x35f5:
          goto code_r0x0073254e;
        case 0x35f6:
          goto code_r0x00732558;
        case 0x35f7:
          goto code_r0x00732562;
        case 0x35f8:
          goto code_r0x0073256c;
        case 0x35f9:
          goto code_r0x00732576;
        case 0x35fa:
          goto code_r0x00732580;
        case 0x35fb:
          goto code_r0x0073258a;
        case 0x35fc:
          goto code_r0x00732594;
        case 0x35fe:
          goto code_r0x0073259e;
        case 0x3600:
          goto code_r0x007325a8;
        case 0x3601:
          goto code_r0x007325b2;
        case 0x3602:
          goto code_r0x007325bc;
        case 0x3603:
          goto code_r0x007325c6;
        }
      }
    }
    else {
      switch(param_1) {
      case 0x3605:
        goto code_r0x007325ef;
      case 0x3606:
        goto code_r0x007325f9;
      case 0x3607:
        goto code_r0x00732603;
      case 0x3608:
        goto code_r0x0073260d;
      case 0x3609:
        goto code_r0x00732617;
      case 0x360a:
        goto code_r0x00732621;
      case 0x360b:
        goto code_r0x0073262b;
      case 0x360c:
        goto code_r0x00732635;
      case 0x360d:
        goto code_r0x0073263f;
      case 0x360e:
        goto code_r0x00732649;
      case 0x360f:
        goto code_r0x00732653;
      case 0x3610:
        goto code_r0x0073265d;
      case 0x3611:
        goto code_r0x00732667;
      case 0x3612:
        goto code_r0x00732671;
      case 0x3613:
        goto code_r0x0073267b;
      case 0x3614:
        goto code_r0x00732685;
      case 0x3615:
        goto code_r0x0073268f;
      case 0x3616:
        goto code_r0x00732699;
      case 0x3617:
        goto code_r0x007326a3;
      case 0x3618:
        goto code_r0x007326ad;
      case 0x3619:
        goto code_r0x007326b7;
      case 0x361a:
        goto code_r0x007326c1;
      case 0x361b:
        goto code_r0x007326cb;
      case 0x361c:
        goto code_r0x007326d5;
      case 0x361d:
        goto code_r0x007326df;
      case 0x361e:
        goto code_r0x007326e9;
      case 0x361f:
        goto code_r0x007326f3;
      case 0x3620:
        goto code_r0x007326fd;
      }
    }
  }
  else if (param_1 < 0x36b1) {
    if (param_1 == 14000) {
LAB_0073283d:
      return L"ERROR_SXS_SECTION_NOT_FOUND";
    }
    switch(param_1) {
    case 0x3622:
code_r0x00732739:
      return L"ERROR_IPSEC_IKE_INVALID_FILTER";
    case 0x3623:
code_r0x00732743:
      return L"ERROR_IPSEC_IKE_OUT_OF_MEMORY";
    case 0x3624:
code_r0x0073274d:
      return L"ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED";
    case 0x3625:
code_r0x00732757:
      return L"ERROR_IPSEC_IKE_INVALID_POLICY";
    case 0x3626:
code_r0x00732761:
      return L"ERROR_IPSEC_IKE_UNKNOWN_DOI";
    case 0x3627:
code_r0x0073276b:
      return L"ERROR_IPSEC_IKE_INVALID_SITUATION";
    case 0x3628:
code_r0x00732775:
      return L"ERROR_IPSEC_IKE_DH_FAILURE";
    case 0x3629:
code_r0x0073277f:
      return L"ERROR_IPSEC_IKE_INVALID_GROUP";
    case 0x362a:
code_r0x00732789:
      return L"ERROR_IPSEC_IKE_ENCRYPT";
    case 0x362b:
code_r0x00732793:
      return L"ERROR_IPSEC_IKE_DECRYPT";
    case 0x362c:
code_r0x0073279d:
      return L"ERROR_IPSEC_IKE_POLICY_MATCH";
    case 0x362d:
code_r0x007327a7:
      return L"ERROR_IPSEC_IKE_UNSUPPORTED_ID";
    case 0x362e:
code_r0x007327b1:
      return L"ERROR_IPSEC_IKE_INVALID_HASH";
    case 0x362f:
code_r0x007327bb:
      return L"ERROR_IPSEC_IKE_INVALID_HASH_ALG";
    case 0x3630:
code_r0x007327c5:
      return L"ERROR_IPSEC_IKE_INVALID_HASH_SIZE";
    case 0x3631:
code_r0x007327cf:
      return L"ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG";
    case 0x3632:
code_r0x007327d9:
      return L"ERROR_IPSEC_IKE_INVALID_AUTH_ALG";
    case 0x3633:
code_r0x007327e3:
      return L"ERROR_IPSEC_IKE_INVALID_SIG";
    case 0x3634:
code_r0x007327ed:
      return L"ERROR_IPSEC_IKE_LOAD_FAILED";
    case 0x3635:
code_r0x007327f7:
      return L"ERROR_IPSEC_IKE_RPC_DELETE";
    case 0x3636:
code_r0x00732801:
      return L"ERROR_IPSEC_IKE_BENIGN_REINIT";
    case 0x3637:
code_r0x0073280b:
      return L"ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY";
    case 0x3639:
code_r0x00732815:
      return L"ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN";
    case 0x363a:
code_r0x0073281f:
      return L"ERROR_IPSEC_IKE_MM_LIMIT";
    case 0x363b:
code_r0x00732829:
      return L"ERROR_IPSEC_IKE_NEGOTIATION_DISABLED";
    case 0x363c:
code_r0x00732833:
      return L"ERROR_IPSEC_IKE_NEG_STATUS_END";
    }
  }
  else if (param_1 < 0x30201) {
    if (param_1 == 0x30200) {
      return L"STG_S_CONVERTED";
    }
    switch(param_1) {
    case 0x36b1:
LAB_0073286f:
      return L"ERROR_SXS_CANT_GEN_ACTCTX";
    case 0x36b2:
code_r0x00732879:
      return L"ERROR_SXS_INVALID_ACTCTXDATA_FORMAT";
    case 0x36b3:
code_r0x00732883:
      return L"ERROR_SXS_ASSEMBLY_NOT_FOUND";
    case 0x36b4:
code_r0x0073288d:
      return L"ERROR_SXS_MANIFEST_FORMAT_ERROR";
    case 0x36b5:
code_r0x00732897:
      return L"ERROR_SXS_MANIFEST_PARSE_ERROR";
    case 0x36b6:
code_r0x007328a1:
      return L"ERROR_SXS_ACTIVATION_CONTEXT_DISABLED";
    case 0x36b7:
code_r0x007328ab:
      return L"ERROR_SXS_KEY_NOT_FOUND";
    case 0x36b8:
code_r0x007328b5:
      return L"ERROR_SXS_VERSION_CONFLICT";
    case 0x36b9:
code_r0x007328bf:
      return L"ERROR_SXS_WRONG_SECTION_TYPE";
    case 0x36ba:
code_r0x007328c9:
      return L"ERROR_SXS_THREAD_QUERIES_DISABLED";
    case 0x36bb:
      goto LAB_007328d3;
    case 0x36bc:
      goto LAB_007328dd;
    case 0x36bd:
      goto LAB_007328e7;
    case 0x36be:
      goto LAB_007328f1;
    case 0x36bf:
      goto LAB_007328fb;
    case 0x36c0:
      goto LAB_00732905;
    case 0x36c1:
      goto LAB_0073290f;
    case 0x36c2:
      goto LAB_00732919;
    case 0x36c3:
      goto LAB_00732923;
    case 0x36c4:
      goto LAB_0073292d;
    case 0x36c5:
      goto LAB_00732937;
    case 0x36c6:
      goto LAB_00732941;
    case 0x36c7:
      goto LAB_0073294b;
    case 0x36c8:
      goto LAB_00732955;
    case 0x36c9:
      goto LAB_0073295f;
    case 0x36ca:
      goto LAB_00732969;
    case 0x36cb:
      goto LAB_00732973;
    case 0x36cc:
      goto LAB_0073297d;
    case 0x36cd:
      goto LAB_00732987;
    case 0x36ce:
      goto LAB_00732991;
    case 0x36cf:
      goto LAB_0073299b;
    case 0x36d0:
      goto LAB_007329a5;
    case 0x36d1:
      goto LAB_007329af;
    case 0x36d2:
      goto LAB_007329b9;
    case 0x36d3:
      goto LAB_007329c3;
    case 0x36d4:
      goto LAB_007329cd;
    case 0x36d5:
      goto LAB_007329d7;
    case 0x36d6:
      goto LAB_007329e1;
    case 0x36d7:
      goto LAB_007329eb;
    case 0x36d8:
      goto LAB_007329f5;
    case 0x36d9:
      goto LAB_007329ff;
    case 0x36da:
      goto LAB_00732a09;
    case 0x36db:
      goto LAB_00732a13;
    case 0x36dc:
      goto LAB_00732a1d;
    case 0x36dd:
      goto LAB_00732a27;
    case 0x36de:
      goto LAB_00732a31;
    case 0x36df:
      goto LAB_00732a3b;
    case 0x36e0:
      goto LAB_00732a45;
    case 0x36e1:
      goto LAB_00732a4f;
    case 0x36e2:
      goto LAB_00732a59;
    case 0x36e3:
      goto LAB_00732a63;
    case 0x36e4:
      goto LAB_00732a6d;
    case 0x36e5:
      goto LAB_00732a77;
    case 0x36e6:
      goto LAB_00732a81;
    case 0x36e7:
      goto LAB_00732a8b;
    case 0x36e8:
      goto LAB_00732a95;
    case 0x36e9:
      goto LAB_00732a9f;
    case 0x36ea:
      goto LAB_00732aa9;
    case 0x36eb:
      goto LAB_00732ab3;
    case 0x36ec:
      goto LAB_00732abd;
    case 0x36ed:
      goto LAB_00732ac7;
    case 0x36ee:
      goto LAB_00732ad1;
    case 0x36ef:
      goto LAB_00732adb;
    case 0x36f0:
      goto LAB_00732ae5;
    case 0x36f1:
      goto LAB_00732aef;
    case 0x36f2:
      goto LAB_00732af9;
    case 0x36f3:
      goto LAB_00732b03;
    case 0x36f4:
      goto LAB_00732b0d;
    case 0x36f5:
      goto LAB_00732b17;
    case 0x36f6:
      goto LAB_00732b21;
    case 0x36f7:
      goto LAB_00732b2b;
    case 0x36f8:
      goto LAB_00732b35;
    case 0x36f9:
      goto LAB_00732b3f;
    case 0x36fa:
      goto LAB_00732b49;
    case 0x36fb:
      goto LAB_00732b53;
    case 0x36fc:
      goto LAB_00732b5d;
    case 0x36fd:
      goto LAB_00732b67;
    case 0x36fe:
      goto LAB_00732b71;
    case 0x36ff:
      goto LAB_00732b7b;
    case 0x3700:
      goto LAB_00732b85;
    }
  }
  else if (param_1 < 0x40251) {
    if (param_1 == 0x40250) {
      return L"VFW_S_RESOURCE_NOT_NEEDED";
    }
    if (param_1 < 0x40151) {
      if (param_1 == 0x40150) {
        return L"REGDB_S_FIRST";
      }
      if (param_1 < 0x40011) {
        if (param_1 == 0x40010) {
          return L"WBEM_S_PARTIAL_RESULTS";
        }
        if (param_1 < 0x40003) {
          if (param_1 == 0x40002) {
            return L"OLE_S_MAC_CLIPFORMAT & MS_S_NOUPDATE";
          }
          if (param_1 < 0x30206) {
            if (param_1 == 0x30205) {
              return L"STG_S_CONSOLIDATIONFAILED";
            }
            if (param_1 == 0x30201) {
              return L"STG_S_BLOCK";
            }
            if (param_1 == 0x30202) {
              return L"STG_S_RETRYNOW";
            }
            if (param_1 == 0x30203) {
              return L"STG_S_MONITORING";
            }
            if (param_1 == 0x30204) {
              return L"STG_S_MULTIPLEOPENS";
            }
          }
          else {
            if (param_1 == 0x30206) {
              return L"STG_S_CANNOTCONSOLIDATE";
            }
            if (param_1 == 0x40000) {
              return L"OLE_S_FIRST";
            }
            if (param_1 == 0x40001) {
              return L"OLE_S_STATIC & MS_S_PENDING";
            }
          }
        }
        else {
          if (param_1 == 0x40003) {
            return L"MS_S_ENDOFSTREAM & WBEM_S_DIFFERENT";
          }
          if (param_1 == 0x40004) {
            return L"WBEM_S_TIMEDOUT";
          }
          if (param_1 == 0x40005) {
            return L"WBEM_S_NO_MORE_DATA";
          }
          if (param_1 == 0x40006) {
            return L"WBEM_S_OPERATION_CANCELLED";
          }
          if (param_1 == 0x40007) {
            return L"WBEM_S_PENDING";
          }
          if (param_1 == 0x40008) {
            return L"WBEM_S_DUPLICATE_OBJECTS";
          }
          if (param_1 == 0x40009) {
            return L"WBEM_S_ACCESS_DENIED";
          }
        }
      }
      else if (param_1 < 0x40111) {
        if (param_1 == 0x40110) {
          return L"CLASSFACTORY_S_FIRST";
        }
        if (param_1 == 0x40017) {
          return L"WBEM_S_SOURCE_NOT_AVAILABLE";
        }
        if (param_1 == 0x400ff) {
          return L"OLE_S_LAST";
        }
        if (param_1 == 0x40100) {
          return L"DRAGDROP_S_FIRST";
        }
        if (param_1 == 0x40101) {
          return L"DRAGDROP_S_CANCEL";
        }
        if (param_1 == 0x40102) {
          return L"DRAGDROP_S_USEDEFAULTCURSORS";
        }
        if (param_1 == 0x40103) {
          return L"VFW_S_NO_MORE_ITEMS";
        }
        if (param_1 == 0x4010f) {
          return L"DRAGDROP_S_LAST";
        }
      }
      else {
        if (param_1 == 0x4011f) {
          return L"CLASSFACTORY_S_LAST";
        }
        if (param_1 == 0x40120) {
          return L"MARSHAL_S_FIRST";
        }
        if (param_1 == 0x4012f) {
          return L"MARSHAL_S_LAST";
        }
        if (param_1 == 0x40130) {
          return L"DATA_S_FIRST";
        }
        if (param_1 == 0x4013f) {
          return L"DATA_S_LAST";
        }
        if (param_1 == 0x40140) {
          return L"VIEW_S_FIRST";
        }
        if (param_1 == 0x4014f) {
          return L"VIEW_S_LAST";
        }
      }
    }
    else if (param_1 < 0x401d0) {
      if (param_1 == 0x401cf) {
        return L"CONVERT10_S_LAST";
      }
      if (param_1 < 0x40190) {
        if (param_1 == 0x4018f) {
          return L"OLEOBJ_S_LAST";
        }
        if (param_1 < 0x40180) {
          if (param_1 == 0x4017f) {
            return L"CACHE_S_LAST";
          }
          if (param_1 == 0x4015f) {
            return L"REGDB_S_LAST";
          }
          if (param_1 == 0x40170) {
            return L"CACHE_S_FIRST";
          }
          if (param_1 == 0x40171) {
            return L"CACHE_S_SAMECACHE";
          }
          if (param_1 == 0x40172) {
            return L"CACHE_S_SOMECACHES_NOTUPDATED";
          }
        }
        else {
          if (param_1 == 0x40180) {
            return L"OLEOBJ_S_FIRST";
          }
          if (param_1 == 0x40181) {
            return L"OLEOBJ_S_CANNOT_DOVERB_NOW";
          }
          if (param_1 == 0x40182) {
            return L"OLEOBJ_S_INVALIDHWND";
          }
        }
      }
      else {
        if (param_1 == 0x40190) {
          return L"CLIENTSITE_S_FIRST";
        }
        if (param_1 == 0x4019f) {
          return L"CLIENTSITE_S_LAST";
        }
        if (param_1 == 0x401a0) {
          return L"INPLACE_S_FIRST";
        }
        if (param_1 == 0x401af) {
          return L"INPLACE_S_LAST";
        }
        if (param_1 == 0x401b0) {
          return L"ENUM_S_FIRST";
        }
        if (param_1 == 0x401bf) {
          return L"ENUM_S_LAST";
        }
        if (param_1 == 0x401c0) {
          return L"CONVERT10_S_FIRST";
        }
      }
    }
    else if (param_1 < 0x401e8) {
      if (param_1 == 0x401e7) {
        return L"MK_S_MONIKERALREADYREGISTERED";
      }
      if (param_1 == 0x401d0) {
        return L"CLIPBRD_S_FIRST";
      }
      if (param_1 == 0x401df) {
        return L"CLIPBRD_S_LAST";
      }
      if (param_1 == 0x401e0) {
        return L"MK_S_FIRST";
      }
      if (param_1 == 0x401e2) {
        return L"MK_S_REDUCED_TO_SELF";
      }
      if (param_1 == 0x401e4) {
        return L"MK_S_ME";
      }
      if (param_1 == 0x401e5) {
        return L"MK_S_HIM";
      }
      if (param_1 == 0x401e6) {
        return L"MK_S_US";
      }
    }
    else {
      if (param_1 == 0x401ef) {
        return L"MK_S_LAST";
      }
      if (param_1 == 0x40202) {
        return L"EVENT_S_NOSUBSCRIBERS";
      }
      if (param_1 == 0x4022d) {
        return L"VFW_S_DUPLICATE_NAME";
      }
      if (param_1 == 0x40237) {
        return L"VFW_S_STATE_INTERMEDIATE";
      }
      if (param_1 == 0x40242) {
        return L"VFW_S_PARTIAL_RENDER";
      }
      if (param_1 == 0x40245) {
        return L"VFW_S_SOME_DATA_IGNORED";
      }
      if (param_1 == 0x40246) {
        return L"VFW_S_CONNECTIONS_DEFERRED";
      }
    }
  }
  else if (param_1 < 0x4d00b) {
    if (param_1 == 0x4d00a) {
      return L"XACT_S_LOCALLY_OK";
    }
    if (param_1 < 0x41304) {
      if (param_1 == 0x41303) {
        return L"SCHED_S_TASK_HAS_NOT_RUN";
      }
      if (param_1 < 0x40271) {
        if (param_1 == 0x40270) {
          return L"VFW_S_NO_STOP_TIME";
        }
        if (param_1 < 0x40261) {
          if (param_1 == 0x40260) {
            return L"VFW_S_ESTIMATED";
          }
          if (param_1 == 0x40254) {
            return L"VFW_S_MEDIA_TYPE_IGNORED";
          }
          if (param_1 == 0x40257) {
            return L"VFW_S_VIDEO_NOT_RENDERED";
          }
          if (param_1 == 0x40258) {
            return L"VFW_S_AUDIO_NOT_RENDERED";
          }
          if (param_1 == 0x4025a) {
            return L"VFW_S_RPZA";
          }
        }
        else {
          if (param_1 == 0x40263) {
            return L"VFW_S_RESERVED";
          }
          if (param_1 == 0x40267) {
            return L"VFW_S_STREAM_OFF";
          }
          if (param_1 == 0x40268) {
            return L"VFW_S_CANT_CUE";
          }
        }
      }
      else {
        if (param_1 == 0x4027e) {
          return L"VFW_S_NOPREVIEWPIN";
        }
        if (param_1 == 0x40280) {
          return L"VFW_S_DVD_NON_ONE_SEQUENTIAL";
        }
        if (param_1 == 0x4028c) {
          return L"VFW_S_DVD_CHANNEL_CONTENTS_NOT_AVAILABLE";
        }
        if (param_1 == 0x4028d) {
          return L"VFW_S_DVD_NOT_ACCURATE";
        }
        if (param_1 == 0x41300) {
          return L"SCHED_S_TASK_READY";
        }
        if (param_1 == 0x41301) {
          return L"SCHED_S_TASK_RUNNING";
        }
        if (param_1 == 0x41302) {
          return L"SCHED_S_TASK_DISABLED";
        }
      }
    }
    else if (param_1 < 0x4d003) {
      if (param_1 == 0x4d002) {
        return L"XACT_S_READONLY";
      }
      if (param_1 == 0x41304) {
        return L"SCHED_S_TASK_NO_MORE_RUNS";
      }
      if (param_1 == 0x41305) {
        return L"SCHED_S_TASK_NOT_SCHEDULED";
      }
      if (param_1 == 0x41306) {
        return L"SCHED_S_TASK_TERMINATED";
      }
      if (param_1 == 0x41307) {
        return L"SCHED_S_TASK_NO_VALID_TRIGGERS";
      }
      if (param_1 == 0x41308) {
        return L"SCHED_S_EVENT_TRIGGER";
      }
      if (param_1 == 0x4d000) {
        return L"XACT_S_FIRST";
      }
      if (param_1 == 0x4d001) {
        return L"XACT_S_DEFECT";
      }
    }
    else {
      if (param_1 == 0x4d003) {
        return L"XACT_S_SOMENORETAIN";
      }
      if (param_1 == 0x4d004) {
        return L"XACT_S_OKINFORM";
      }
      if (param_1 == 0x4d005) {
        return L"XACT_S_MADECHANGESCONTENT";
      }
      if (param_1 == 0x4d006) {
        return L"XACT_S_MADECHANGESINFORM";
      }
      if (param_1 == 0x4d007) {
        return L"XACT_S_ALLNORETAIN";
      }
      if (param_1 == 0x4d008) {
        return L"XACT_S_ABORTING";
      }
      if (param_1 == 0x4d009) {
        return L"XACT_S_SINGLEPHASE";
      }
    }
  }
  else if (param_1 < 0x15000b) {
    if (param_1 == 0x15000a) {
      return L"DV_HALFDUPLEX";
    }
    if (param_1 < 0x90315) {
      if (param_1 == 0x90314) {
        return L"SEC_I_COMPLETE_AND_CONTINUE";
      }
      if (param_1 == 0x4d010) {
        return L"XACT_S_LAST";
      }
      if (param_1 == 0x4e000) {
        return L"CONTEXT_S_FIRST";
      }
      if (param_1 == 0x4e02f) {
        return L"CONTEXT_S_LAST";
      }
      if (param_1 == 0x80012) {
        return L"CO_S_NOTALLINTERFACES";
      }
      if (param_1 == 0x80013) {
        return L"CO_S_MACHINENAMENOTFOUND";
      }
      if (param_1 == 0x90312) {
        return L"SEC_I_CONTINUE_NEEDED";
      }
      if (param_1 == 0x90313) {
        return L"SEC_I_COMPLETE_NEEDED";
      }
    }
    else {
      if (param_1 == 0x90315) {
        return L"SEC_I_LOCAL_LOGON";
      }
      if (param_1 == 0x90317) {
        return L"SEC_I_CONTEXT_EXPIRED";
      }
      if (param_1 == 0x90320) {
        return L"SEC_I_INCOMPLETE_CREDENTIALS";
      }
      if (param_1 == 0x90321) {
        return L"SEC_I_RENEGOTIATE";
      }
      if (param_1 == 0x90323) {
        return L"SEC_I_NO_LSA_CONTEXT";
      }
      if (param_1 == 0x91012) {
        return L"CRYPT_I_NEW_PROTECTION_REQUIRED";
      }
      if (param_1 == 0x150005) {
        return L"DV_FULLDUPLEX";
      }
    }
  }
  else if (param_1 < 0x8781203) {
    if (param_1 == 0x8781202) {
      return L"DMUS_S_END";
    }
    if (param_1 == 0x150010) {
      return L"DV_PENDING";
    }
    if (param_1 == 0x876086f) {
      return L"D3DOK_NOAUTOGEN";
    }
    if (param_1 == 0x878000a) {
      return L"DS_NO_VIRTUALIZATION";
    }
    if (param_1 == 0x8781091) {
      return L"DMUS_S_PARTIALLOAD";
    }
    if (param_1 == 0x8781092) {
      return L"DMUS_S_PARTIALDOWNLOAD";
    }
    if (param_1 == 0x8781200) {
      return L"DMUS_S_REQUEUE";
    }
    if (param_1 == 0x8781201) {
      return L"DMUS_S_FREE";
    }
  }
  else {
    if (param_1 == 0x8781210) {
      return L"DMUS_S_STRING_TRUNCATED";
    }
    if (param_1 == 0x8781211) {
      return L"DMUS_S_LAST_TOOL";
    }
    if (param_1 == 0x8781212) {
      return L"DMUS_S_OVER_CHORD";
    }
    if (param_1 == 0x8781213) {
      return L"DMUS_S_UP_OCTAVE";
    }
    if (param_1 == 0x8781214) {
      return L"DMUS_S_DOWN_OCTAVE";
    }
    if (param_1 == 0x8781215) {
      return L"DMUS_S_NOBUFFERCONTROL";
    }
    if (param_1 == 0x8781216) {
      return L"DMUS_S_GARBAGE_COLLECTED";
    }
  }
  return L"Unknown";
}

